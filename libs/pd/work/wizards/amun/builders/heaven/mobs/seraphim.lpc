#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Seraphim");
    set("id", ({ "seraphim", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Seraphim" );
    set("long", "%^BOLD%^%^WHITE%^Seraphim is the highest order of angels in Heaven. She has been described as incorruptible, brilliant and powerful. She is the closest of the angels with the Father and is in direct communication with Him. It is said that she is so radiant that not even Cherubim can look upon her.%^RESET%^" );
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
