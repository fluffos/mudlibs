
#include <std.h>

#define FAIL(s) return notify_fail(s+"\n")

inherit FOOD;

string *PIE_TYPES = ({
  "blueberry",
  "blackberry",
  "raspberry",
  "strawberry",
  "cherry",
  "banana cream",
  "chocolate cream",
  "coconut cream",
});

int throw_pie(string);
string type;

void create() {
  ::create();
  type = PIE_TYPES[random(sizeof(PIE_TYPES))];
  set_name("pie");
  set_id( ({ type+" pie" }) );
  set_short("a yummy "+type+" pie");
  set_long("This pie has a flakey brown crust and a "+type+" filling.\n"
      "It would look great splattered on someone's face.");
  set_smell("default", "The pie smells delicious.");
  set_weight(5);
  set_curr_value("gold", 0);
  set_strength(35+random(7));
  set_servings(2+random(2));
}

void init() {
  ::init();
  add_action("throw_pie", "throw");
}

int throw_pie(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string what, who;

  if (!str) return 0;

  if (sscanf(str, "%s at %s", what, who) != 2)
    what = str;

  if (present(what, tp) != this_object())
    return 0;

  if (who)
    tgt = present(who, env);
  else
    tgt = tp->query_current_attacker();

  if (tp->query_busy())
    FAIL("You are busy.");

  if (tp->query_sp() < 20)
    FAIL("You're too tired!");

  if (!tgt)
    FAIL("Throw what at whom?");

  if (!tgt->is_living() || tp == tgt)
    FAIL("That wouldn't be any fun.");

  if (!tp->kill_ob(tgt))
    FAIL("You cannot attack "+tgt->query_cap_name()+".");

  tp->set_disable(1);
  tp->add_sp(-(12+random(9)));

  message("combat", "You throw the "+type+" pie right into "+
      tgt->query_cap_name()+"'s face!", tp);
  message("combat", tp->query_cap_name()+" throws a "+type+" pie "
      "that hits you right in the face!\n"
      "The pie gets in your eyes and blinds you!", tgt);
  message("combat", tp->query_cap_name()+" throws a pie at "+
      tgt->query_cap_name()+" and hits "+tgt->query_objective()+
      "in the face!", env, ({ tp, tgt }) );

  tgt->set_blind(2+random(3));

  remove_action("throw_pie", "throw");
  call_out("remove_me", 0);

  return 1;
}

void remove_me() { this_object()->remove(); }

