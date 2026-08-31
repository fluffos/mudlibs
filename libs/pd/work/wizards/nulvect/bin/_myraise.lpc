
#include <std.h>
#include <dirs.h>

#define RES "%^RESET%^"
#define COL "%^BOLD%^%^BLACK%^"
#define COL2 "%^BOLD%^%^WHITE%^"

#define FAIL(s) return notify_fail(s+"\n")

#define RAISE_DIR DIR_CLASS_CMDS+"/obj/raise/"

inherit DAEMON;

mapping undeads = ([
  "skeleton" : ([
    "necromancy" : 35,
    "corpse" : 1,
  ]),
  "zombie" : ([
    "necromancy" : 70,
    "corpse" : 1,
  ]),
  "wight" : ([
    "necromancy" : 110,
    "corpse" : 1,
  ]),
  "spectre" : ([
    "necromancy" : 150,
    "corpse" : 0,
  ]),
  "nightstalker" : ([
    "necromancy" : 200,
    "corpse" : 0,
  ]),
]);

int spell() {
  object tp = this_player();
  if (tp && tp->query_subclass() == "necromancer" &&
      tp->query_skill("necromancy") >= 35)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <raise [undead]>\n"
    "        <raise list>\n\n"
    "This spell allows a necromancer to raise an undead monster. "
    "He may then <command> it to do his bidding, but an unskilled "
    "caster could lose control.\n"
    "Commanding an undead to <reveal powers> will show any special "
    "abilities it may have, and they can "
    "<assist> or <stop assisting> anyone.",
    this_player() );
}

int can_cast(object tp, string str) {
  
  if (!tp) return 0;

  if (environment(tp)->query_property("no magic"))
    FAIL("Some force prevents your magic.");

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("The energies involved could destroy you in your state.");

  if (!strlen(str))
    FAIL("Raise what?");

  if (str != "list")
    if (!undeads[str] ||
        tp->query_skill("necromancy") < undeads[str]["necromancy"])
          FAIL("You do not know how to raise that.");

  if (sizeof(filter(tp->query_pets(), (: $1->id($2) :), str)))
    FAIL("You cannot control more than one "+str+" at a time.");

  if (str != "list" && tp->query_mp() < undeads[str]["necromancy"])
    FAIL("Your magic power is too low.");

  return 1;
}

int cmd_myraise(string str) {
  object tp = this_player();
  object env = environment(tp);
  object ob;
  string *list;
  int req, cost;

  if (!spell()) return 0;

  if (!can_cast(tp, str)) return 0;

  if (str == "list") {
    list = keys(filter(undeads, (:
      $3->query_skill("necromancy") >= $2["necromancy"]
    :), tp));
    list = sort_array(list, (:
      $3[$1]["necromancy"] > $3[$2]["necromancy"] ? 1 : -1
    :), undeads );
    list = map(list, (: "  "+capitalize($1) :) );
    message("info",
      "  %^BOLD%^%^WHITE%^Known Undead%^RESET%^\n"
      "%^BOLD%^%^BLUE%^+=+=+=+=+=+=+=+=%^RESET%^\n"+
      implode(list, "\n")+"\n", tp);
    return 1;
  }

  req = undeads[str]["necromancy"];
  cost = req;
  cost += random(cost/2);

  if (tp->query_mp() < cost)
    FAIL("Your magic power is too low.");

  tp->set_magic_round(1);
  tp->add_mp(-cost);

  if (random(req/2) > random(tp->query_skill("necromancy"))) {
    message("magic", "Your spell fails to raise anything.", tp);
    return 1;
  }

  ob = new(RAISE_DIR+str);
  if (!ob)
    FAIL("An error occurred, please contact a staff member.");

  message("magic", COL+"You raise "+indefinite_article(str)+
    " from beyond the grave!"+RES, tp);
  message("magic", COL+tp->query_cap_name()+" raises "+
    indefinite_article(str)+" from beyond the grave!"+RES,
    env, tp);

  ob->set_name(str);
  ob->set_owner(tp);
  ob->move(env);

  message("magic", COL2+ob->query_raise_msg()+RES, env);

  tp->add_skill_points("necromancy", req/2);

  return 1;
}
