#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("ogre mage");
    set_id( ({ "ogre", "ogre2" }) );
    set_class("mage");
    set_subclass("wizard");
    set_level(40);
    set_short("ogre mage");
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 2 and a half feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "dark", "pillar", "fog", "manamissile", "coalesce", }) );
    set_spell_chance(60); 
    set_skill("melee", 100);
    set_skill("wizardry", 250);
    set_skill("magic attack", 250);
    set_skill("conjuring", 250);
    set_aggressive(13+random(13));
    new(DRAG_ARM "ogre_pants")->move(this_object());
    force_me("wear pants");
}
