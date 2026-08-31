
#include <std.h>

#define FAIL(s) return notify_fail(s)

inherit DAEMON;

int abil() {
  object tp = this_player();
  if (tp && tp->query_class() == "rogue" && tp->query_level() >= 3)
    return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <lockpick [door]>\n"
    "        <lockpick [direction]>\n"
    "        <lockpick [container]>\n\n"
    "This command will allow you to attempt to pick a lock on either a door "
    "or a locked container. Some tools can help your chance of success.",
    this_player() );
}

int can_cast(object tp, object tgt, string door_id) {
  if (!tp) return;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your hands go right through it!");

  if (!tgt)
    FAIL("Lockpick what?");

  if ((door_id && !tgt->query_locked(door_id)) ||
     (!door_id && !tgt->query_locked()))
       FAIL("It is not locked!");

  if (tp->query_sp() < 10)
    FAIL("You are too tired.");

  return 1;
}

int cmd_lockpick(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  object *tools;
  int bonus, penalty, chance, strength, points;
  string door_id, mymsg, envmsg;
  string *doors;

  if (str) {
    if (door_id = env->query_door_id(str)) {
      tgt = env;
    }
    else if (sizeof(doors = env->query_doors_blocking_exit(str))) {
      door_id = doors[0];
      tgt = env;
    }
    else {
      tgt = present(str, env);
      if (!tgt) {
        tgt = present(str, tp);
      }
    }
  }

  if (!can_cast(tp, tgt, door_id)) return 0;

  chance = tp->query_skill("locks");

  tools = filter(all_inventory(tp), (: $1->query_property("lockpicking tool") :) );
  if (sizeof(tools)) {
    tools = sort_array(tools, function(object ob1, object ob2) {
      int a1 = ob1->query_property("lockpicking tool");
      int a2 = ob2->query_property("lockpicking tool");
      if (a1 > a2) return -1;
      if (a1 < a2) return 1;
      return 0;
    } );
    bonus = tools[0]->query_property("lockpicking tool");
  }
  chance += bonus;

  chance += random(10) - random(15);

  if (door_id)
    strength = tgt->query_lock_strength(door_id);
  else
    strength = tgt->query_lock_strength();
  if (!strength) strength = random(101);

  penalty = tgt->query_property("magic hold");
  strength += penalty;

  tp->add_sp(-(5+random(5)));
  tp->set_disable();

  if (chance < strength) {
    // failed to pick it
    points = 5+random(5);
    mymsg = "You fail to pick the lock.";
    envmsg = tp->query_cap_name()+" fails to pick the lock of "+
      definite_article(str)+".";
  }
  else {
    // success
    if (door_id)
      tgt->set_locked(door_id, 0);
    else
      tgt->set_locked(0);
    points = 10+random(strength/2);
    mymsg = "You successfully pick the lock.";
    envmsg = tp->query_cap_name()+" successfully picks the lock of "+
      definite_article(str)+".";
  }

  tp->add_skill_points("locks", points);

  message("info", mymsg, tp);
  if (!tp->use_stealth(2))
    message("info", envmsg, env, tp);

  return 1;
}
