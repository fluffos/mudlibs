#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Archangel");
    set("id", ({ "archangel", "monster", "angel" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Archangel%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Archangel is the messenger of God, in some religions called the Archangeloi, she is high-ranked amoung the angels and is said to be the most important mediator between God and mankind. Archangel is believed to command the heavenly army in an ongoing war with Satan and his legion of angels. She is the special emissaries of Principality, transmitting the good intentions that the Angel Virutes bring from Power to humanity. Archangel has a protective and special love for all the persons of earth, intervening in crises and times of need to protect and guard nations, cities, airports, churches, houses, and families. She brings great goodness and much happiness to those she aids.%^RESET%^" );
    set("race", "archangel" ); 
    set_gender( "female" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set_alignment(200);
    set("aggressive", 55);
    set_spells( ({ "rush", "holyfire", "levin", "mystify" }) );
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
