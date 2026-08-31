#include <std.h>
#include <dragonevent.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Ogre");
    set_id( ({ "ogre" }) );
    set_class("fighter");
    set_subclass("warrior");
    set_level(55);
    set_short("Ogre" );
    set_long("%^RESET%^%^GREEN%^This nasty looking ogre stands about 6 feet taller than the average human. He has nasty %^BOLD%^%^YELLOW%^yellow teeth %^RESET%^%^GREEN%^that compliment his pale green skin.%^RESET%^" );
    set_race( "ogre" ); 
    set_gender( "male" );
    set_body_type("ogre");
    set_spells( ({ "coupedegrace", "bash", "jab", "whirl", }) );
    set_spell_chance(60); 
    set_skill("melee", 330);
    set_skill("blunt", 330);
    set_aggressive(13+random(13));
    new(DRAG_ARM "ogre_pants")->move(this_object());
    new(DRAG_WEP "ogre_club")->move(this_object());
    new(DRAG_WEP "ogre_club")->move(this_object());
    force_me("wear pants");
    force_me("wield club");
    force_me("wield club");
}
