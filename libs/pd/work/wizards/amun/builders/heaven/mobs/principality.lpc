#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Principality");
    set("id", ({ "principality", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Principality%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Principality is the guardian of all large groups - like nations, big cities, religions and large corporations. She influences all races through ideas and circumstances that they stir up. She sometimes even interferes with human affairs to accomplish the direct will of God. Principality is the Archangel that influences life-styles of those who inhabit their spheres of authority in the indirect will of God.%^RESET%^" );
    set("race", "archangel" ); 
    set_gender( "female" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set_alignment(200);
    set("aggressive", 55);
    set_spells( ({ "rush", "holyfire", "levin" }) );
    set_spell_chance(60); 
    new(HEVARM "white_pants")->move(this_object());
    new(HEVARM "white_robes")->move(this_object());
    new(HEVARM "white_shirt")->move(this_object());
    new(HEVARM "wings_of_light")->move(this_object());
    new(HEVARM "holy_halo")->move(this_object());
    force_me("wear pants");
    force_me("wear robes");
    force_me("wear shirt");
    force_me("wear wings");
    force_me("wear halo");
    set_max_hp(9500);
    set_exp(190000);
}
