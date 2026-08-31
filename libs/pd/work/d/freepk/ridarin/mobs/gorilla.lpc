
#include <std.h>
#include <daemons.h>

inherit MONSTER;

int cmd_pound(string str);

void create() {
  ::create();
  set_id( ({ "gorilla", "huge gorilla" }) );
  set_name("gorilla");
  set_short("a huge gorilla");
  set_long(
    "This gorilla is very large and muscular. His long arms reach down "
    "so far that his knuckles drag the ground. Black fur covers most of "
    "his back, while his face, chest and stomach are covered in dark "
    "weathered skin. Behind his snarl, bright eyes gleam with intelligence."
  );
  set_gender("male");
  set_level(51+random(3));
  set_race("gorilla");
  set_body_type("human");
  set_emotes(10, ({
    "The huge gorilla pounds his chest in anger!",
    "The huge gorilla bares his teeth and grunts loudly at you!",
  }), 1);
  set_aggressive(55+random(11));
  set_class("animal");
  set_subclass("strong");
  set_spell_chance(50);
  set_spells( ({ "pound" }) );
  add_action("cmd_pound", "pound");
}

int cmd_pound(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string RES = "%^RESET%^";
  string COL = "%^BOLD%^%^WHITE%^";
  int dmg, cost;

  if (tp != this_object()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!tgt) return 0;

  if (!tp->query_is_limb("right hand") &&
      !tp->query_is_limb("left hand")) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 4,
    ({ "attack", "melee" }),
    ({ "strength" }),
    ({ "strength", "dexterity" }) );

  dmg = dmg * 125 / 100;

  cost = BALANCE3_D->get_cost(dmg, 4, "sp");

  if (tp->query_sp() < cost) return 0;

  tp->add_sp(-cost);
  tp->set_disable(1);

  message("combat", "You "+COL+"pound"+RES+" your fist into "+
                    tgt->query_cap_name()+"!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"pounds"+RES+" "+
                    tp->query_possessive()+" fist into you!", tgt );
  message("combat", tp->query_cap_name()+" "+COL+"pounds"+RES+" "+
                    tp->query_possessive()+" fist into "+
		    tgt->query_cap_name()+"!", env, ({ tp, tgt }) );

  tgt->do_damage(tgt->return_target_limb(), dmg);

  return 1;
}

