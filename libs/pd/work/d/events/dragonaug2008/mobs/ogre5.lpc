#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Ogre");
    set_id( ({ "ogre", "ogre5" }) );
    set_class("rogue");
    set_subclass("thug");
    set_level(45);
    set_short("Ogre" );
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 4 feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "clobber", "hurl", "smash", "dirt", }) );
    set_spell_chance(50); 
    set_skill("melee", 270);
    set_aggressive(13+random(13));
    new(DRAG_ARM "ogre_pants")->move(this_object());
    new(DRAG_WEP "ogre_club")->move(this_object());
    force_me("wear pants");
}
