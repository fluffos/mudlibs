
#include <std.h>
#include <daemons.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RESONATE_PROP "resonate_spell_times"

#define RES "%^RESET%^"
#define COL RES+"%^GREEN%^"

#define ESSENCE "%^BOLD%^e%^RESET%^%^GREEN%^s%^BOLD%^s%^RESET%^%^GREEN%^e%^BOLD%^n%^RESET%^%^GREEN%^c%^BOLD%^e%^RESET%^"
#define SKY "%^BOLD%^%^BLUE%^s%^WHITE%^k%^BLUE%^y%^RESET%^"

varargs int query_waiting(object, string);
void set_waiting(object, string, int);

mapping resonatetypes = ([
  "bison" : "%^ORANGE%^b%^WHITE%^i%^ORANGE%^s%^WHITE%^o%^ORANGE%^n",
  "bear" : "%^RED%^b%^BOLD%^%^BLACK%^e%^RESET%^%^RED%^a%^BOLD%^%^BLACK%^r",
  "lion" : "%^CYAN%^l%^GREEN%^i%^CYAN%^o%^GREEN%^n",
]);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "druid" &&
      tp->query_skill("nature") >= 180)
        return 1;
  return 0;
}

string type() { return "faith"; }

void help() {
  message("help",
    "Syntax: <resonate [type]>\n\n"
    "Strong druids can call the spirit of the bear, the lion, or the bison "
    "into all those who have banded together with the druid.",
    this_player() );
}

int can_cast(object tp, object *players, string type) {
  
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You are but a spirit yourself.");

  if (!type || !strlen(type))
    FAIL("Resonate which spirit?");

  if (!sizeof(players))
    FAIL("There is no one around to use this on!");

  if (member_array(type, keys(resonatetypes)) == -1)
    FAIL("You do not know how to resonate that spirit.");

  if (tp->query_mp() < 100)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_resonate(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *players;
  string type, party;
  int time, cost;

  if (!spell()) return 0;

  if (str) type = str;
  if (type) type = remove_article(type);

  if (type) {
    party = tp->query_party();
    if (strlen(party)) {
      players = filter(all_inventory(env), (:
        $1->is_player() &&
        $1 != this_player() &&
        stringp($1->query_party()) &&
        $1->query_party() == $2 &&
        !$1->query_ghost() &&
        !query_waiting($1, $3)
      :), party, type);
    }
  }

  if (!can_cast(tp, players, type)) return 0;

  time = tp->query_stats("wisdom")*4 + random(tp->query_stats("intelligence")*2);
  cost = tp->query_skill("nature")/5 + random(tp->query_stats("wisdom")/3);

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  message("magic", COL+"You call the "+ESSENCE+COL+" of the "+
    resonatetypes[type]+COL+" into the room!"+RES, tp);
  message("magic", COL+"The %^BOLD%^%^BLACK%^ghostly"+COL+" image of "+
    indefinite_article(type)+" "+resonatetypes[type]+COL+" enters the room, "
    "and flies into the "+SKY+COL+"!"+RES, env);

  call_out("buff_on", 4, time, players, tp, type);

  tp->add_mp(-cost);
  tp->set_magic_round(1);
  tp->add_skill_points("nature", time/20 + 2);

  return 1;
}

varargs int query_waiting(object ob, string type) {
  mapping times = ob->query(RESONATE_PROP);

  if (!times || !sizeof(times)) return 0;

  if (nullp(type))
    return sizeof(filter(times, (: $2 > time() :) )) ? 1 : 0;

  return times[type] > time();
}

void set_waiting(object ob, string type, int time) {
  mapping times = ob->query(RESONATE_PROP);
  if (!times) times = ([]);
  times[type] = time()+time;
  ob->set(RESONATE_PROP, times);
}

void buff_on(int time, object *players, object caster, string type) {
  if (!players) return;
  foreach (object player in players) {
    if (!player) continue;
    if (query_waiting(player, type)) continue;
    set_waiting(player, type, time);
    call_other(this_object(), type+"_on", player, caster, time);

    message("magic",
      "%^GREEN%^The "+resonatetypes[type]+"%^RESET%^%^GREEN%^"
      " flys down and enters "+player->query_cap_name()+"!%^RESET%^",
      environment(player), player);     

    message("magic",
      "%^GREEN%^The "+resonatetypes[type]+"%^RESET%^%^GREEN%^ enters you!%^RESET%^", player);
  }
  DELAY_D->add_delay(time, this_object(), "buff_off", ({ players, type }), 1);
}

void buff_off(object *players, string type) {
  if (!players) return;
  foreach (object player in players) {
    if (!player) continue;
    if (!query_waiting(player, type)) continue;
    set_waiting(player, type, 0);

    message("magic",
      "%^GREEN%^The "+resonatetypes[type]+"%^RESET%^%^GREEN%^"
      " leaves "+player->query_cap_name()+"!%^RESET%^", 
      environment(player), player);

    message("magic",
      "%^GREEN%^The "+resonatetypes[type]+"%^RESET%^%^GREEN%^ leaves you!%^RESET%^", player);
  }
}

void bison_on(object player, object caster, int time) {
  player->add_skill_bonus("defense", caster->query_base_skill("nature")/9, time);
  player->add_stat_bonus("constitution", caster->query_base_stats("wisdom")/6, time);
}

void lion_on(object player, object caster, int time) {
  player->add_skill_bonus("melee", caster->query_base_skill("nature")/9, time);
  player->add_stat_bonus("dexterity", caster->query_base_stats("wisdom")/6, time);
}

void bear_on(object player, object caster, int time) {
  player->add_skill_bonus("attack", caster->query_base_skill("nature")/9, time);
  player->add_stat_bonus("strength", caster->query_base_stats("wisdom")/6, time);
}
