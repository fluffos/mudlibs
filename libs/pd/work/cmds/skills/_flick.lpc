
#include <std.h>
#include <daemons.h>
#include <objects.h>
#include <damage_types.h>
#include <damage.h>

#define FAIL(s) return notify_fail(s+"\n")

#define RES "%^RESET%^"

inherit DAEMON;

mapping colors = ([
  "platinum" : "%^BOLD%^%^WHITE%^",
  "gold" : "%^YELLOW%^",
  "electrum" : "%^BOLD%^%^BLACK%^",
  "silver" : "%^BOLD%^%^CYAN%^",
  "copper" : "%^ORANGE%^",
]);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_level() >= 2)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <flick [currency] [at whom]>\n"
    "        <flick [how many] [currency] [at whom]>\n\n"
    "This is a weak jester attack that allows you to flick "
    "money at someone. "
    "The more the coin is worth, "
    "the heavier it is and the more damage it can do.",
    this_player() );
}

int can_cast(object tp, object tgt, string cur, int howmany) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("Some force prevents your violence.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("What are you, a poltergeist?");

  if (!tgt || !cur)
    FAIL("Flick what at whom?");

  if (!tgt->is_living())
    FAIL("That would be pointless.");

  if (tgt == tp)
    FAIL("You flick a coin into the air and catch it.");

  if (tp->query_sp() < 10)
    FAIL("You are too tired.");

  if (howmany < 1)
    FAIL("Very funny.");

  if (tp->query_money(cur) < howmany)
    FAIL("You don't have "+
         (howmany==1 ? "any" : "that many")+
         " "+cur+" coins!");

  if (!tp->ok_to_kill(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  return 1;
}

int cmd_flick(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object pile;
  object *piles;
  int howmany, dmg, cost, mult, miss, max, hit, dodge;
  string cur, col, who, msg;

  if (!abil()) return 0;

  if (str)
    if (sscanf(str, "%d %s coins at %s", howmany, cur, who) != 3)
      if (sscanf(str, "%d %s coin at %s", howmany, cur, who) != 3)
        if (sscanf(str, "%d %s at %s", howmany, cur, who) != 3)
          if (sscanf(str, "%s at %s", cur, who) != 2)
            if (sscanf(str, "%d %s", howmany, cur) != 2) {
              cur = str;
              howmany = 1;
            }

  if (who)
    tgt = present(who, env);
  else
    tgt = tp->query_current_attacker();

  max = 2;
  if (tp->query_level() >= 5)
   max += 1 + (tp->query_level()-5)/10;
  if (howmany > max)
    howmany = max;

  if (nullp(howmany)) howmany = 1;

  if (!can_cast(tp, tgt, cur, howmany)) return 0;

  cost = random(5)+howmany*2;

  if (tp->query_sp() < cost)
    FAIL("You are too tired.");

  tp->kill_ob(tgt);

  col = colors[cur];
  if (!col) col = colors["gold"];

  if (howmany == 1)
    msg = "a "+col+cur+" coin"+RES;
  else
    msg = ""+howmany+" "+col+cur+" coins"+RES;

  message("combat", "You flick "+msg+" at "+tgt->query_cap_name()+"!", tp);
  message("combat", tp->query_cap_name()+" flicks "+msg+" at you!", tgt);
  message("combat", tp->query_cap_name()+" flicks "+msg+" at "+
    tgt->query_cap_name()+"!", env, ({ tp, tgt }) );

  switch (cur) {
    case "platinum": mult = 55; break;
    case "gold": mult = 48; break;
    case "electrum": mult = 39; break;
    case "silver": mult = 31; break;
    case "copper": mult = 22; break;
    default: mult = 34;
  }

  miss = 0;

  hit = tp->query_stats("dexterity")+10;
  dodge = tgt->query_stats("dexterity");

  for (int i = 0; i < howmany; i++) {

    if ((i && random(100) < 25) || hit < dodge+random(10)-random(5)) {
      miss++;
      continue;
    }

    dmg = BALANCE3_D->get_damage(tp, tgt, 1,
      ({ "entertainment" }),
      ({ "dexterity" }) );

    dmg = dmg*mult/100;

    if (dmg > 70) dmg = 70 + (dmg-70)/3;

    tgt->do_damage("random", dmg+random(5), DAMAGE_PHYSICAL | DAMAGE_IMPACT, DAMAGE_NO_SEVER | DAMAGE_NONLETHAL, tp);

    mult /= 3;
    if (mult < 1) mult = 1;
  }
  
  piles = filter(all_inventory(env), (: $1->is_money_pile() :) );
  if (sizeof(piles))
    pile = piles[0];
  else {
    pile = new(OB_COINS);
    pile->set_last_holder(tp->query_name());
  }

  if (miss) {
    pile->add_money(cur, miss);
    if (howmany == 1)
      message("combat", "The coin misses completely!", env);
    else
      message("combat", capitalize(cardinal(miss))+
        " of the coins miss"+(miss==1 ? "es" : "")+" completely!", env);
  }

  for (int i = howmany - miss; i > 0; i--) {
    if (random(200) < 100)
      tgt->add_money(cur, 1);
    else
      pile->add_money(cur, 1);
  }

  if (!sizeof(piles)) {
    if (sizeof(pile->query_currencies()))
      pile->move(env);
    else
      pile->remove();
  }

  tp->add_money(cur, -howmany);
  tp->set_disable();
  tp->add_sp(-cost);
  tp->add_skill_points("entertainment", 8+random(8));
  
  return 1;
}

