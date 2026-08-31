#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("ogre mage");
    set_id( ({ "ogre", "ogre3" }) );
    set_class("mage");
    set_subclass("necromancer");
    set_level(43);
    set_short("ogre mage" );
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 3 feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "shadowburst", "disease", "umbra me", "raise skeleton", "raise spectre", "raise wight", "raise zombie" }) );
    set_spell_chance(60); 
    set_skill("melee", 100);
    set_aggressive(13+random(13));
    set_swarm(1);
    new(DRAG_ARM "ogre_pants")->move(this_object());
    force_me("wear pants");
}

void heart_beat() {
  object to = this_object();
  object env;
  object *pets;
  ::heart_beat();
  if (!to || !(env = environment())) return;

  pets = filter(all_inventory(env), (: $1->query_owner() == $2 :), to );
  if (sizeof(pets)) pets->add_assist(to);
}
