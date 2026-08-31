
#include <std.h>
#include <daemons.h>

inherit MONSTER;

int cmd_gore(string str);

void create() {
  ::create();
  set_id( ({ "warthog", "wart hog", "hog" }) );
  set_name("warthog");
  set_short("a warthog");
  set_long("This dark brown cousin of the pig looks extremely "
           "unfriendly. It has coarse bristly hairs sticking out "
	   "all over, and two large tusks.");
  set_gender("male");
  set_race("warthog");
  set_body_type("hog");
  set_emotes(10, ({
    "The warthog huffs angrily!",
    "The warthog lowers its tusks into an attack position.",
  }), 1);
  set_aggressive(40+random(11));
  set_class("animal");
  set_subclass("strong");
  set_level(30+random(3));
  set_spell_chance(45);
  set_spells( ({ "gore" }) );
  add_action("cmd_gore", "gore");
}

int cmd_gore(string str) {
  object tp = this_player();
  object env = environment(tp);
  object tgt;
  string RES = "%^RESET%^";
  string COL = "%^RED%^";
  int dmg, cost;

  if (tp != this_object()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!tgt) return 0;

  if (!tp->query_is_limb("tusks")) return 0;

  dmg = BALANCE3_D->get_damage(tp, tgt, 3,
    ({ "attack" }),
    ({ "strength" }),
    ({ "strength", "dexterity" }) );

  dmg = dmg * 125 / 100;

  cost = BALANCE3_D->get_cost(dmg, 3, "sp");

  if (tp->query_sp() < cost) return 0;

  tp->add_sp(-cost);
  tp->set_disable(1);

  message("combat", "You "+COL+"gore"+RES+" "+tgt->query_cap_name()+
                    " with your tusks!", tp);
  message("combat", tp->query_cap_name()+" "+COL+"gores"+RES+" you "
                    " with "+tp->query_possessive()+" tusks!", tgt );
  message("combat", tp->query_cap_name()+" "+COL+"gores"+RES+" "+
                    tgt->query_cap_name()+" with "+tp->query_possessive()+
		    " tusks!", env, ({ tp, tgt }));

  tgt->do_damage(tgt->return_target_limb(), dmg);

  return 1;
}
