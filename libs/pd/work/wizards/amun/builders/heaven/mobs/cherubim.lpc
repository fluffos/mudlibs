#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Cherubim");
    set("id", ({ "cherubim", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Cherubim%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^The Cherubim is one of the most brilliant and mighty of all the angels who dwell close to God in the Seventh Heaven. She is the second-highest order of angels in Heaven. She is sometimes referred to as Cherub, but is not to be mistaken for the baby angels, also referred to as Cherubs. According to the Book of Enochs, Cherubim is very majestic and beautiful.%^RESET%^" );
    set("race", "archangel" ); 
    set_gender( "female" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set_alignment(200);
    set("aggressive", 55);
    set_spells( ({ "rush", "holyfire", "mystify" }) );
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
