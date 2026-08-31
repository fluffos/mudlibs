//      /bin/user/_build.c
//      ranger ability to build fires/shelter
//      created by Nightshade 11-10-01
//      shelter added by Djerr 11-12-01
//  rewritten by Nulvect 2006-08-05
#include <std.h>

#define BUILD "/cmds/skills/obj/build/"
#define FAIL(s) return notify_fail(s)

inherit DAEMON;

string use_resources(object tp, string type);
mixed *check_resources(object tp, string type);

mapping reqs = ([
  "fire" : ([
    "wood" : 2
  ]),
  "shelter" : ([
    "wood" : 2,
    "sinew" : 1,
    "skins" : 1
  ])
]);

mapping obids = ([
  "wood" : "forage_wood_ob",
  "sinew" : "gut_sinew_ob",
  "skins" : "skin_skin_ob"
]);

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "ranger" &&
      tp->query_skill("nature") >= 40)
        return 1;
  return 0;
}

string type() { return "other"; }

void help() {
  message("help",
    "Syntax: <build [fire | shelter]>\n\n"
    "Rangers can build a fire to warm themselves "
    "and brew tea, or build a shelter for protection.",
    this_player());
}

int can_cast(object tp, string type) {
  object env;
  string what;
  mixed *err;
  
  if (!tp) return 0;

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.\n");

  if (member_array(type, keys(reqs)) == -1)
    FAIL("You cannot build that.\n");
  
  err=check_resources(tp, type);
  
  if (stringp(err[0]))
    FAIL("You do not have enough "+err[0]+" to make a "+type+".\n");

  env = environment(tp);

  if (present("build_"+type+"_ob",env))
    FAIL("There is already a "+type+" here.\n");

  switch (type) {
    case "shelter":
      if (env->query_property("shelter"))
        FAIL("You cannot build a shelter inside a shelter!\n");
    break;
    default:
  }
  
  return 1;
}

int cmd_build(string str) {
  object tp=this_player();
  object env=environment(tp);
  
  if (!abil()) return 0;

  if (!str || str == "")
    FAIL("Build what?\n");

  if (str == "campfire")
    str = "fire";

  if (!can_cast(tp, str))
    return 0;

  tp->set_disable();
  tp->set_paralyzed(6,"You are busy building a "+str+".");
  tp->add_sp(-(20+random(10)));

  message("info", "You begin to build a "+str+".", tp);
  message("info", tp->query_cap_name()+" begins to build a "+str+".", env, tp);

  call_out("build_"+str, 6, ({tp}) );

  return 1;
}

void build_fire(mixed *args) {
  object tp=args[0];
  object env;
  object ob;
  string err;
  int nat;

  if (!tp) return;

  if (sizeof(err=use_resources(tp, "fire"))) {
    message("info","You seem to be missing some "+err+".",tp);
    return;
  }

  env = environment(tp);
  nat = tp->query_skill("nature");

  if (nat < random(50) + 20) {
    message("info", "A gust of wind blows out your fire.",tp);
    message("info", "A gust of wind blows out "+tp->query_cap_name()+"'s fire.",
      env, tp);
  }
  else {
    message("info", "Your fire spreads and catches.", tp);
    message("info", tp->query_cap_name()+"'s fire comes to life.", env, tp);
    ob=new(BUILD+"campfire");
    ob->setup(nat/25);
    ob->move(env);
  }

}

void build_shelter(mixed *args) {
  object tp=args[0];
  object env;
  object ob;
  string err;
  int nat;

  if (!tp) return;

  if (sizeof(err=use_resources(tp, "shelter"))) {
    message("info","You seem to be missing some "+err+".",tp);
    return;
  }
  
  env = environment(tp);
  nat = tp->query_skill("nature");

  if (nat < random(45) + 25) {
    message("info","Your poorly made shelter collapses.", tp);
    message("info",tp->query_cap_name()+"'s poorly made shelter collapses.", env, tp);
  }
  else {
    message("info","You build a secure shelter.", tp);
    message("info",tp->query_cap_name()+" builds a secure shelter.", env, tp);
    ob=new(BUILD+"shelter");
    ob->setup(nat+40, BUILD+"shelter_room", base_name(env));
    ob->move(env);
  }

}

mixed *check_resources(object tp, string type) {
  mapping resources = ([
    "wood" : ({}),
    "skins" : ({}),
    "sinew" : ({})
  ]);
  object *ret = ({});
  object *ai = all_inventory(tp);

  foreach (string req in keys(reqs[type])) {
    resources[req] = filter(ai, 
      function(object thing, string id) {
        if (thing->id(id)) return 1;
        else return 0;
      }, obids[req]);
    if (sizeof(resources[req]) < reqs[type][req])
      return ({req});
    for (int i=0; i < reqs[type][req]; i++)
      ret += ({resources[req][i]});
  }
  return ret;
}

// the only way we could be missing resources is if
// somebody stole them...
string use_resources(object tp, string type) {
  mixed *delme = check_resources(tp, type);
  if (stringp(delme[0]))
    return delme[0];
  else
    delme->remove();
  return "";
}

