#include <std.h>

inherit PET;

void create() {
  ::create();
  set_name("ferret");
  set_id( ({ "mischevious ferret" }) );
  set_short("a mischevious ferret");
  set_long("The ferret is brown and black with a long body. "
      "Around his eyes is a black mask shaped marking, and "
      "it always seems like he's grinning.");
  set_gender("male");
  set_race("ferret");
  set_body_type("quadrupe");
  set_class("rogue");
  set_subclass("thief");
  set_level(25);
  set_stats("dexterity", 80);
  set_stats("charisma", 70);
  set_stats("intelligence", 70);
  set_stats("strength", 10);
  set_sp(query_max_sp());
  set_mp(query_max_mp());
  set_skill("stealing", 250);
  set_skill("stealth", 250);
  set_skill("agility", 250);
  set_skill("perception", 250);
  set_spells( ({ "pick", "dodge", "dart", }) );
  set_spell_chance(76);
  set_reveal("He loves to steal things.");
  set_exp_percent(75);
}

void heart_beat() {
  object *livs;
  object tgt;
  ::heart_beat();
  if (!this_object() || !environment()) return;

  if (random(100) < 83 || query_current_attacker()) return;

  livs = all_inventory(environment());
  livs = filter(livs, (: $1->is_living() :) );
  livs = filter(livs, (: (!$1->query_owner() || $1->query_owner() != $2) :), query_owner());
  livs -= ({ this_object(), query_owner() });

  if (sizeof(livs)) {
    tgt = livs[random(sizeof(livs))];
    if (!query_stolen(tgt))
      command("pick "+tgt->query_name());
  }

}

int use_stealth(mixed x) { return 1; }
int query_stealth() { return 25; }
