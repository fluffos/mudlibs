// based on trap abil by Nightshade
// written by Nulvect 2006-08-08

#include <std.h>
#include <daemons.h>

#define TRAP_OB "/cmds/skills/obj/trap_ob"
#define FAIL(s) return notify_fail(s)

inherit DAEMON;

int canpk(object tp);
mixed *check_resources(object tp);

mapping reqs = ([
  "wood" : 2,
  "sinew" : 3
]);

mapping obids = ([
  "wood" : "forage_wood_ob",
  "mud" : "forage_mud_ob",
  "sinew" : "gut_sinew_ob",
  "skins" : "skin_skin_ob"
]);

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "ranger" &&
      tp->query_skill("nature") >= to_int(18*5.5) &&
      tp->query_skill("stealth") >= 18*3)
        return 1;
  return 0;
}

string type() { return "deception"; }

void help() {
  message("help",
    "Syntax: <trap>\n\n"
    "Rangers can make traps out of natural materials, and set them in a room "
    "to catch their victims off guard.",
    this_player());
}

int can_cast(object tp) {
  mixed *err;

  if (!tp) return 0;

  if (tp->query_ghost())
    FAIL("You can't do that as a ghost.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are too busy.\n");

  if (environment(tp)->query_property("no attack"))
    FAIL("You cannot set a trap here.\n");

  if (present("trap_ob_id",environment(tp)))
    FAIL("There is already a trap here.\n");
  
  if (tp->is_player()) {
    err=check_resources(tp);
    if (stringp(err[0]))
      FAIL("You do not have enough "+err[0]+" to make a trap.\n");
  }
  
  return 1;
}

int cmd_trap(string str) {
  object tp=this_player();
  object trap;
  int st, nat;
  
  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  if (tp->query_sp() < 30)
    FAIL("You are too tired to set a trap.\n");
  
  if (!objectp(trap=new(TRAP_OB))) {
    message("info","An error ocurred, please contact an immortal.",tp);
    return 1;
  }

  message("info","You deftly set a trap.",tp);
  message("info",tp->query_cap_name()+" assembles something.", environment(tp), tp);

  if (tp->is_player())
    check_resources(tp)->remove();

  
  tp->set_disable();
  tp->add_sp(-(random(30)));

  st=tp->query_skill("stealth");
  nat=tp->query_skill("nature");

  trap->setup(tp, canpk(tp), st+nat/4, nat+st);
  trap->move(environment(tp));

  tp->add_skill_points("stealth", nat/6);
  tp->add_skill_points("nature", st/4);

  return 1;
}

int canpk(object tp) {
  if (tp->query_level() < 20 ||
      environment(tp)->query_zone() == "nopk")
        return 0;
  return 1;
}

mixed *check_resources(object tp) {
  mapping resources = ([
    "wood" : ({}),
    "sinew" : ({})
  ]);
  object *ret = ({});
  object *ai = all_inventory(tp);

  foreach (string req in keys(reqs)) {
    resources[req] = filter(ai,
      function (object thing, string id) {
        if (thing->id(id)) return 1;
        else return 0;
      }, obids[req]);
    if (sizeof(resources[req]) < reqs[req])
      return ({req});
    for (int i=0; i < reqs[req]; i++)
      ret += ({resources[req][i]});
  }
  return ret;
}


