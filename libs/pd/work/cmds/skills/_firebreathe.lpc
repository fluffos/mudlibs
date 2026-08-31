
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")
#define RETFAIL(s) return message("info", s, tp)

#define RES "%^RESET%^"
#define COL RES+"%^CYAN%^"
#define COL2 "%^BOLD%^%^RED%^"

#define FIREBREATHE_PROP "firebreathe_abil_time"
#define FIREBREATHE_DELAY 8
#define SING_FAIL "sing_fail_time"

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 50*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <firebreathe [whom]>\n\n"
    "A very difficult form of entertainment, the user drinks some alcohol "
    "and uses a flame to light his breath on fire. If aimed at someone, "
    "the resulting fireball can do a lot of damage.",
    this_player() );
}

int can_cast(object tp, object tgt, object *fires, int alc) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");
  
  if (tp->query_ghost())
    FAIL("You're dead!");

  if (present("song_ob_id", tp))
    FAIL("You can't draw enough breath while singing.");

  if ((int)tp->query(FIREBREATHE_PROP)+FIREBREATHE_DELAY > time())
    FAIL("Performing that again so soon would surely burn your throat!");

  if (!sizeof(fires))
    FAIL("You must have an open flame!");

  if (alc < 25)
    FAIL("You must drink "+(alc?"more":"some")+" alcohol first!");

  if (!tgt)
    FAIL("Aim it at whom?");

  if (!tgt->is_living())
    FAIL("There are far easier ways to light things on fire.");

  if (tgt == tp)
    FAIL("Toasty!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  if (tp->query_sp() < 50)
    FAIL("You are too tired.");

  return 1;
}

int cmd_firebreathe(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *fires;
  int alc;

  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  alc = tp->query_intox();

  fires = filter(all_inventory(tp), (:
//    ($1->query_lit() && $1->query_fuel())
    $1->query_lit()
  :) );

  if (!can_cast(tp, tgt, fires, alc)) return 0;

  message("combat", "You take a deep breath and ready the flame.", tp);
  message("combat", tp->query_cap_name()+" breathes deeply and holds "
                    "a flame ready.", env, tp);

  tp->set_disable(2);
  tp->set(SING_FAIL, time()+2);

  call_out("do_firebreathe", 2, ({ tp, env, tgt }) );

  return 1;
}

void do_firebreathe(mixed *args) {
  object tp = args[0];
  object env = args[1];
  object tgt = args[2];
  int rank, dmg, cost, alc, mult;
  string tmp;

  if (!tp) return;

  if (!env || environment(tp) != env) return;
  if (!tgt || environment(tgt) != env)
    RETFAIL("Your opponent is not here!");
  if (!tp->kill_ob(tgt))
    RETFAIL("You cannot attack "+tgt->query_cap_name()+".");

  alc = tp->query_intox();
  if (alc > 100) alc = 100;
  alc = 1 + alc*3/4 + random(alc/4);
  mult = 20;
  mult += alc/10;

  rank = 4;

  dmg = BALANCE3_D->get_damage(tp, tgt, rank,
    ({ "entertainment", "entertainment", "attack" }),
    ({ "charisma", "dexterity" }),
    ({ "intelligence" }) );

  dmg = dmg*mult/10;

//  cost = dmg/18;
  cost = BALANCE3_D->get_cost(dmg, 4, "sp") * 3 / 4;

  if (tp->query_sp() < cost)
    RETFAIL("You are too tired to continue.");

  tmp =
  COL2+"h"+COL+"u"+COL2+"g"+COL+"e "+COL2+"fi"+COL+"re"+COL2+"ba"+COL+"ll"+RES;

  message("combat", "You blow out a "+tmp+" that "+COL2+"burns"+RES+" "+
    tgt->query_cap_name()+" badly!", tp);
  message("combat", tp->query_cap_name()+" blows out a "+tmp+" that "+
    COL2+"burns"+RES+" you badly!", tgt);
  message("combat", tp->query_cap_name()+" blows out a "+tmp+" that "+
    COL2+"burns"+RES+" "+tgt->query_cap_name()+" badly!", env, ({ tp, tgt }) );

  tp->add_sp(-cost);
  tp->add_intox(-alc);
  tgt->do_damage("random", dmg, DAMAGE_PHYSICAL | DAMAGE_FIRE, DAMAGE_NO_SEVER, tp);

  tp->set(FIREBREATHE_PROP, time());
}

