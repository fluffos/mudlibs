#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("Power");
    set("id", ({ "power", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^YELLOW%^Power%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^Power is said to be the first angel created by God, she is the guardian of the passageways leading to Heaven, and resides between the First and Second Heavens. She is the guide to lost souls and bring balance to the earth. Because of Power, humanity is able to maintain balance within their spirits. Power is also the recoder of the history of mankind, and it is said that she prevents the efforts of demons to take control of the world. Power is also said to preside over demons, or perhaps (According to Saint Paul) is herself evil.%^RESET%^" );
    set("race", "archangel" ); 
    set_gender( "female" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set_alignment(75);
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
