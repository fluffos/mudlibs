#include <std.h>
#include <daemons.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s)

#define COL "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"

inherit DAEMON;

void do_enchant(object *obs, int bonus, int time);
void end_enchant(mixed *args);

void help() {
  message("help",
    "Syntax: <enchant [object]>\n"
    "        <enchant armour>\n"
    "        <enchant weapons>\n\n"
    "This spell makes swords sharper, clubs heavier, armour sturdier, "
    "and gems shinier - in short, it improves an item's natural qualities. "
    "It also grants the ability to absorb or deal magical damage.",
   this_player() );
}

int spell() {
  object tp = this_player();
  string *allowed = ({ "wizard", "sorceror", "black" });
  if (tp && member_array(tp->query_subclass(), allowed) != -1 &&
      tp->query_skill("conjuring") >= 100)
        return 1;
  return 0;
}

string type() { return "conjuring"; }

int can_cast(object tp, object *obs) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails.");

  if (!obs || !sizeof(obs))
    FAIL("Enchant what?");

  if (sizeof(filter(obs->query_enchanted(), (: $1 == 1 :)) == sizeof(obs)))
    FAIL((sizeof(obs) == 1 ? "It is" : "They are")+" already enchanted.");

  if (tp->query_mp() < 100)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_enchant(string str) {
  object tp = this_player();
  object env = environment(tp);
  object *obs;
  int bonus, time, cost;
  string mymsg, theirmsg;

  if (!spell()) return 0;

  if (str) {
    if (str == "armour")
      obs = filter(all_inventory(tp), (: $1->is_armour() :) );
    else if (str == "weapons")
      obs = filter(all_inventory(tp), (: $1->is_weapon() :) );
    else {
      obs = allocate(1);
      obs[0] = present(str, tp);
      if (!obs[0])
        obs[0] = present(str, env);
      if (!obs[0]) obs = 0; // clear it out so can_cast detects failure
    }
  }

  if (!can_cast(tp, obs)) return 0;

  obs = filter(obs, (: $1->query_enchanted() == 0 :) );

  bonus = 1;
  bonus += (tp->query_skill("conjuring")-75)/50;
  bonus += tp->query_stats("intelligence")/40;
  if (bonus > 4)
    bonus = 4 + (bonus-4)/2;

  time = 60*10;
  time += tp->query_stats("wisdom")*7;

  cost = bonus*10 + random(30) + sizeof(obs)*50;

  if (tp->query_mp() < cost)
    FAIL("Too low on magic.");

  tp->add_mp(-cost);

  if (sizeof(obs) == 1) {
    mymsg = indefinite_article(strip_color(obs[0]->query_short()));
    theirmsg = mymsg;
    tp->set_magic_round(1);
  }
  else {
    mymsg = "your "+str;
    theirmsg = tp->query_possessive()+" "+str;
    tp->set_magic_round(2);
  }

  message("magic", COL+"You work an enchantment upon "+mymsg+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" works a spell upon "+
    theirmsg+"."+RES, env, tp);
  do_enchant(obs, bonus, time);

  return 1;
}

void do_enchant(object *obs, int bonus, int time) {
  mixed *args = ({});
  object *enchanted = ({});

  foreach (object ob in obs) {
    string type;
    string obname = remove_article(strip_color(ob->query_short()));
    string msg;

    if (ob->is_living()) {
      msg = "Nothing happens.";
      continue;
    }

    else if (ob->is_weapon()) {
      ob->add_wc_bonus(bonus);
      msg = "The "+obname+" looks more deadly.";
      type = "wc";
    }

    else if (ob->is_armour()) {
      ob->set_ac(ob->query_ac() + bonus);
      msg = "The "+obname+" looks tougher.";
      type = "ac";
    }

    else {
      mapping vals = ob->query_curr_value();
      if (vals && vals["gold"]) {
        bonus = vals["gold"] * (bonus*8) / 100;
        ob->set_curr_value("gold", vals["gold"] + bonus);
        msg = "The "+obname+" looks more valuable.";
        type = "value";
      }
    }

    enchanted += ({ ob });
    args += ({ ({ ob, type, bonus }) });

    message("magic", COL+msg+RES, environment(ob));

  }

  enchanted->set_enchanted(1);
  enchanted->add_resistance_bonus(DAMAGE_MAGIC, 10+(bonus*5) );
  enchanted->add_damage_bonus(DAMAGE_MAGIC, 10+(bonus*5) );
  DELAY_D->add_delay(time, this_object(), "end_enchant", ({ args }), 1);

}

void end_enchant(mixed *args) {
  foreach (mixed *entry in args) {
    object ob = entry[0];
    string type = entry[1];
    int bonus = entry[2];
    mapping vals;

    if (!ob) continue;

    switch (type) {
      case "wc":
        ob->add_wc_bonus(-bonus);
      break;
      case "ac":
        ob->set_ac(ob->query_ac() - bonus);
      break;
      case "value":
        vals = ob->query_curr_value();
        if (vals && vals["gold"])
          ob->set_curr_value("gold", vals["gold"] - bonus);
      break;
    }

    ob->set_enchanted(0);
    ob->add_resistance_bonus(DAMAGE_MAGIC, -(10+(bonus*5)) );
    ob->add_damage_bonus(DAMAGE_MAGIC, -(10+(bonus*5)) );

    message("magic", COL+"The magical enchantment around "+
      definite_article(strip_color(ob->query_short()))+
      " fades away.", environment(ob));
  }
}

