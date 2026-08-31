#include <std.h>
#include <amun.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("The Father");
    set("id", ({ "father", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^WHITE%^%^The Father%^RESET%^" );
    set("long", "%^BOLD%^%^WHITE%^This is the most powerful being ever known to man and any other race. Almighty, and all powerful are the only words to describe him.%^RESET%^" );
    set("race", "Highest Being" ); 
    set_gender( "male" );
    set_body_type("archangel");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_alignment(200);
    set_class("fighter");
    set("aggressive", 60);
    set_spells( ({ "rush", "holyfire", "levin" }) );
    set_spell_chance(60); 
    new(HEVARM "white_pants")->move(this_object());
    new(HEVARM "white_robes")->move(this_object());
    new(HEVARM "white_shirt")->move(this_object());
    new(HEVARM "wings_of_light")->move(this_object());
    new(HEVARM "holy_halo")->move(this_object());
    if(random(100) > 95)
	new(HEVARM "angelskin_tunic")->move(this_object());
    if(random(100) > 80)
	new(HEVWEP "crystalline_scepter")->move(this_object());
    force_me("wear pants");
    force_me("wear wings");
    force_me("wear halo");
    force_me("wear shirt");
    force_me("wear robes");
    force_me("wear tunic");
    force_me("wield scepter");
    set_max_hp(10000);
    set_exp(230000);
}
