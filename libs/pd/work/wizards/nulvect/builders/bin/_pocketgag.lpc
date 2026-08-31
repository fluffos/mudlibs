
#include <std.h>
#include <dirs.h>

#define FAIL(s) return notify_fail(s+"\n")

#define POCKET_PROP "pocket_abil_time"
#define POCKET_TIME 90
#define POCKET_DIR "/wizards/rull/pocket/"
#define POCKET_ID "pocket_abil_ob_id"

inherit DAEMON;

// entertainment skill req : filename
mapping pocketitems = ([
  90 : "banana",
  105 : "kazoo",
  120 : "ball",
  135 : "hamster",
  160 : "mallet",
  190 : "rabbit",
  220 : "pie",
  260 : "flower",
  300 : "ferret",
//360 : "dummy",
]);

int abil() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "jester" &&
      tp->query_skill("entertainment") >= 18*6)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <pocketgag>\n\n"
    "Great entertainers always have something up their sleeves... "
    "or at least hidden in their pockets. They can grab something "
    "at random to pull out and make their audiences laugh or cry.",
    this_player() );
}

int can_cast(object tp) {

  if (!tp) return 0;

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead! Haha!");

  if (!sizeof(filter(all_inventory(tp), (: $1->query_worn() :) )))
    FAIL("You reach into... wait a second, you're naked!");

  if ((int)tp->query(POCKET_PROP)+POCKET_TIME > time())
    FAIL("You reach into a pocket and pull out "+
         (random(2) ? "some pocket lint" : "a mothball")+".\n"
         "Seems to be empty.");

  if (tp->query_sp() < 40)
    FAIL("You're too tired to do that trick properly.");

  return 1;
}

int cmd_pocketgag(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob;
  string thing;
  int ent;
  mapping myitems;
  string *vals;

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  tp->set_disable();
  tp->add_sp(-(25+random(10)));
  
  ent = tp->query_skill("entertainment");
  myitems = filter(pocketitems, (: $3 >= $1 :), ent);
  vals = values(myitems);
  thing = vals[random(sizeof(vals))];
  ob = new(POCKET_DIR+thing);

  if (!ob)
    FAIL("An error occurred, please contact a staff member.");

  ob->set_id( ({ POCKET_ID }) );

  message("info", "You reach into a pocket and pull out "+
    indefinite_article(ob->query_short())+".", tp);
  message("info", tp->query_cap_name()+" reaches into "+tp->query_possessive()+
    " pocket and pulls out "+indefinite_article(ob->query_short())+".", env, tp);
  
  if (ob->is_living()) {
    ob->move(env);
    ob->set_owner(tp);
  }
  else if (ob->move(tp)) {
    ob->move(env);
    message("info", "Your hands are so full that you fumble and drop it!", tp);
    message("info", tp->query_cap_name()+" clumsily drops it!", env, tp);
    tp->add_skill_points("entertainment", 35);
  }

  tp->add_skill_points("entertainment", 25);
  tp->set(POCKET_PROP, time());

  return 1;
}

