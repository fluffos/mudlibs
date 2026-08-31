#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Throne");
    set("id", ({ "dominion", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Dominion%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Dominion is the Archangel who regulates angelic duties. Through her, the majesty of God is manifested. She usually holds a scepter as an emblem of authority, but she recently lent it to the Father.%^RESET%^" );
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
