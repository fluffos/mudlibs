//Forage command by Stormbringer
//Redone by Nightshade
//11-10-01
// rewritten by Nulvect 2006-08-05

#include <std.h>

#define FAIL(s) return notify_fail(s);
#define FORAGE "/cmds/skills/obj/forage/"

inherit DAEMON;

void forage_mud(object tp, object env, int nat);
void forage_wood(object tp, object env, int nat);
void forage_food(object tp, object env, int nat);
void forage_herbs(object tp, object env, int nat);

mapping forage = ([
  "herbs" : ({"antidote","healing","poison"}),
  "food" : ([
    "forest" : ({"nut","fruit","egg","root","large fruit","melon","large egg"}),
    "mountain" : ({"nut","berry","egg","root","large root","melon","large egg"}),
    "swamp" : ({"garlic","berry","egg","moss","large root","bulb","large egg"}),
    "plains" : ({"garlic","berry","egg","root","large root","onion","large egg"}),
    "beach" : ({"shrimp","berry","soft egg","kelp","fish","clam","crab"})
  ]),
  "wood" : ({
    ([ "short" : "a small twig",
       "ids" : ({ "twig" })
    ]),
    ([ "short" : "a long stick",
       "ids" : ({ "stick" })
    ]),
    ([ "short" : "a branch from a pine",
       "ids" : ({ "branch", "pine"})
    ]),
    ([ "short" : "a thick redwood branch",
       "ids" : ({ "branch", "redwood"})
    ]),
    ([ "short" : "a fine board of cedar",
       "ids" : ({ "board", "cedar" })
    ])
  })
]);

int abil() {
  object tp=this_player();
  if (tp && tp->query_level() >= 5 &&
      tp->query_subclass()=="ranger" &&
      tp->query_skill("nature") >= 25)
        return 1;
  return 0;
}

void help() {
  message("help",
    "Syntax: <forage [mud | wood | food | herbs]>\n\n"
    "This ability allows a ranger to forage for materials in "
    "outdoor areas. Skilled rangers can find more than one "
    "of a given resource at a time. Herbs are, naturally, harder "
    "to find than the others.",
    this_player());
}

int can_cast(object tp) {
  object env;
  
  if (!tp)
    return 0;

  if (tp->query_ghost())
    FAIL("You cannot do that as a ghost.\n");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are too busy at the moment.\n");

  env = environment(tp);

  if (!env)
    FAIL("You are nowhere.\n");
  
  if (!(env->query_property("forest") ||
        env->query_property("mountain") ||
        env->query_property("swamp") ||
        env->query_property("plains") ||
        env->query_property("beach")))
          FAIL("You cannot forage here.\n");

  return 1;
}

int cmd_forage(string str) {
  object tp=this_player();
  object env=environment(tp);
  int nat=tp->query_skill("nature");

  if (!abil()) return 0;

  if (!can_cast(tp)) return 0;

  if(!str)
    FAIL("Forage for what?\n");

  if (function_exists("forage_"+str, this_object()) == 0)
    message("info","You cannot forage for that.",tp);
  else {
    if (!(environment(tp)->do_forage()))
      FAIL("The resources here have been exhausted.\n");
    call_other(this_object(), "forage_"+str, tp, env, nat);
  }

  return 1;
  
}

void forage_mud(object tp, object env, int nat) {
  object mud;

  tp->set_disable();
  tp->add_sp(-(15+random(10)));
  tp->add_skill_points("nature", 10+random(10));
  
  if (random(60) > nat) {
    message("info", "You find nothing in your search.", tp);
    message("info", tp->query_cap_name()+" forages the area.", env, tp);
    return;
  }

  message("info", "You dig up some mud.", tp);
  message("info", tp->query_cap_name()+" digs up some mud.", env, tp);
  for (int i=nat/60+1; i > 0; i--) {
    mud = new(OBJECT);
    mud->set_name("mud ball");
    mud->set_short("a mud ball");
    mud->set_long("A ball of mud");
    mud->set_id(({"forage_mud_ob","mud","ball","mud ball"}));
    mud->set_weight(1);
    mud->move(tp);
    mud=0;
  }
}

void forage_wood(object tp, object env, int nat) {
  object wood;
  string long, short;
  string *ids;
  int r;

  tp->set_disable();
  tp->add_sp(-(20+random(10)));
  tp->add_skill_points("nature", 15+random(10));

  if (random(70) > nat) {
    message("info", "You find nothing in your search.", tp);
    message("info", tp->query_cap_name()+" forages the area.", env, tp);
    return;
  }

  message("info", "You find some wood.", tp);
  message("info", tp->query_cap_name()+" gathers some wood.", env, tp);
  

  for (int i=nat/80+1; i > 0; i--) {
    r=nat/45;
    if (r > 5) r=5;
    r = random(r);
    
    short = forage["wood"][r]["short"];
    long = capitalize(short)+".";
    ids = forage["wood"][r]["ids"];

    wood = new(OBJECT);
    wood->set_name("wood");
    wood->set_short(short);
    wood->set_long(long);
    wood->set_id(ids+({"forage_wood_ob","wood","firewood"}));
    wood->set_weight(2);
    wood->move(tp);
    wood=0;
    ids=({});
  }
}

void forage_food(object tp, object env, int nat) {
  object food;
  int r;
  string where;
  string what;

  tp->add_sp(-(20+random(20)));
  tp->add_skill_points("nature", 20+random(10));
  tp->set_disable();

  if (random(80) > nat) {
    message("info", "You find nothing in your search.", tp);
    message("info", tp->query_cap_name()+" forages the area.", env, tp);
    return;
  }
  
  message("info", "You manage to find some food.", tp);
  message("info", tp->query_cap_name()+" finds some food.", env, tp);

  if (env->query_property("forest"))
    where = "forest";
  else if (env->query_property("mountain"))
    where = "mountain";
  else if (env->query_property("plains"))
    where = "plains";
  else if (env->query_property("swamp"))
    where = "swamp";
  else if (env->query_property("beach"))
    where = "beach";
  else
    where = "forest";

  for (int i=nat/100+1; i > 0; i--) {
    r = random(sizeof(forage["food"][where]));
    what = forage["food"][where][r];
    food = new(FOOD);
    food->set_name(what);
    food->set_id(({what})+explode(what, " "));
    if (member_array(what[0..0], ({"a","e","i","o","u","y"}) ) != -1)
      what = "an "+what;
    else
      what = "a "+what;
    food->set_short(what);
    food->set_long(
      capitalize(what)+", foraged by "+tp->query_cap_name()+" and ready to eat."
    );
    food->set_value(5);
    food->set_strength((r+1)*(nat/10+5)+nat/20);
    food->set_weight(2);
    food->move(tp);
    food=0;
  }

}

void forage_herbs(object tp, object env, int nat) {
  object herb;

  if (nat < 50) {
    message("info","You don't know how to find herbs yet.",tp);
    return;
  }

  tp->add_sp(-(25+random(20)));
  tp->add_skill_points("nature", 25+random(10));
  tp->set_disable();

  if (random(100) > nat) {
    message("info", "You find nothing in your search.", tp);
    message("info", tp->query_cap_name()+" forages the area.", env, tp);
    return;
  }

  message("info", "You manage to gather some herbs.", tp);
  message("info", tp->query_cap_name()+" picks some herbs.", env, tp);

  for (int i=nat/115+1; i > 0; i--) {
    herb = new(FORAGE+"herb");
    herb->set_type(forage["herbs"][random(sizeof(forage["herbs"]))]);
    herb->move(tp);
  }
}

