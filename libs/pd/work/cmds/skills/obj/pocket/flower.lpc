
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n");

#define MAX_SQUIRTS 5

inherit OBJECT;

int do_squirt(string);

int used;

void create() {
  ::create();
  set_name("flower");
  set_id( ({ "pretty flower", "small flower", "small pretty flower" }) );
  set_short("a small pretty flower");
  set_long("On closer inspection, this flower is completely fake!\n"
      "There is a small bulb on the back that you can use "
      "to squirt somebody with water.");
  set_weight(3);
  set_curr_value("gold", 0);
  set_smell("default", "%^BOLD%^%^BLUE%^You get squirted in the face!");
  used = 0;
}

void init() {
  ::init();
  add_action("do_squirt", "squirt");
}

int do_squirt(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  
  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("You're dead!");

  if (used >= MAX_SQUIRTS)
    FAIL("The flower is all out of water.");

  if (tp->query_sp() < 10)
    FAIL("You're too tired.");

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!tgt)
    FAIL("Squirt who?");

  if (!tgt->is_living() || tp == tgt)
    FAIL("That wouldn't be any fun.");

  tp->add_sp(-(5+random(6)));
  tp->set_disable(1);
  used++;

  message("combat", "You offer the flower to "+tgt->query_cap_name()+
      ", and squirt "+tgt->query_objective()+" in the face "
      "at the last second!", tp);
  message("combat", tp->query_cap_name()+" offers a flower to "+
      tgt->query_cap_name()+", which squirts "+tgt->query_objective()+
      "in the face!", env, ({ tp, tgt }) );
  message("combat", tp->query_cap_name()+" offers you a flower.\n"
      "As you start to smell it, you are suddenly squirted in the face!", tgt);

  if (tp->query_stats("charisma") > tgt->query_stats("wisdom") &&
      tgt->kill_ob(tp) ) {
        message("combat", "You feel %^BOLD%^%^RED%^angry%^RESET%^!", tgt);
        message("combat", tgt->query_cap_name()+
            " %^BOLD%^%^RED%^attacks%^RESET%^ you!", tp);
        tgt->add_skill_bonus("attack", 25+random(15), 6);
        tgt->add_skill_bonus("defense", -(25+random(25)), 6);
  }

  return 1;
}
