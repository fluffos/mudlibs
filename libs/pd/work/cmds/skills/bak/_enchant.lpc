#include <std.h>
#include <daemons.h>
#include <damage_types.h>

#define FAIL(s) return notify_fail(s)

#define COL "%^BOLD%^%^BLUE%^"
#define RES "%^RESET%^"

inherit DAEMON;

void end_enchant(mixed *args);

void help() {
  message("help",
    "Syntax: <enchant [object]>\n\n"
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

int can_cast(object tp, object ob) {
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your spell fails.");

  if (!ob)
    FAIL("Enchant what?");

  if (ob->query_enchanted())
    FAIL("It is already enchanted.");

  if (tp->query_mp() < 100)
    FAIL("Too low on magic.");

  return 1;
}

int cmd_enchant(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob;
  string obname, type, msg;
  int bonus, time;

  if (!spell()) return 0;

  if (str) {
    ob = present(str, tp);
    if (!ob)
      ob = present(str, env);
  }

  if (!can_cast(tp, ob)) return 0;

  obname = remove_article(strip_color(ob->query_short()));

  bonus = 1;
  bonus += (tp->query_skill("conjuring")-75)/50;
  bonus += tp->query_stats("intelligence")/40;
  if (bonus > 4)
    bonus = 4 + (bonus-4)/2;

  time = 60*20;
  time += tp->query_stats("wisdom")*25;

  tp->add_mp(-(30 + bonus*10 + random(30)));
  tp->set_magic_round(1);

  message("magic", COL+"You work an enchantment upon "+
    indefinite_article(obname)+"."+RES, tp);
  message("magic", COL+tp->query_cap_name()+" works a spell upon "+
    indefinite_article(obname)+"."+RES, env, tp);

  if (ob->is_living()) {
    msg = "Nothing happens.";
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

  if (type) {
    ob->set_enchanted(1);
    ob->add_resistance_bonus(DAMAGE_MAGIC, 10+(bonus*5) );
    DELAY_D->add_delay(time, this_object(),
      "end_enchant", ({ ({ ob, type, bonus }) }), 1
    );
  }

  if (msg) {
    message("magic", msg, env);
  }

  return 1;
}

void end_enchant(mixed *args) {
  object ob = args[0];
  string type = args[1];
  int bonus = args[2];
  mapping vals;

  if (!ob) return;

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

  message("magic", COL+"The magical enchantment around "+
    definite_article(strip_color(ob->query_short()))+
    " fades away.", environment(ob));
}

