#include <std.h>
#include <amun.h>
inherit MONSTER;
void init() {
    ::init();
    add_action("para","para");
}
void create() {
    ::create();
    set_name("Banshee");
    set("id", ({ "banshee", "monster" }) );
    set_level( 70 );
    set("short", "%^BOLD%^%^WHITE%^Banshee" );
    set("long", "%^RESET%^This Banshee is fierce with her ghostly pale green skin and her long finger nails.  Her wail is overwhelming.%^RESET%^" );
    set("race", "human" ); 
    set_gender( "female" );
    set_body_type("human");
    set_ac("right hand", 7);  
    set_fingers(5); 
    set_class("fighter");
    set_spell_chance(25);
    set_spells( ({"para"}) );
    set("aggressive", 55);
    set_emotes(20, ({"%^BOLD%^%^CYAN%^You are thrown back by the wailing of the banshee!%^RESET%^"}), 1);
    set_max_hp(9500);
    set_exp(220000);
    add_action("para","para");
}

int para() {
    if(this_player()->is_player()) {
	message("info","What?",this_player());
	return 1;
    }
    if(!query_current_attacker()) return 1;
    else {
	message("info", "%^BOLD%^%^CYAN%^You are thrown back by the wailing of the banshee!%^RESET%^",query_current_attacker());
	query_current_attacker()->set_paralyzed(3, "You are too frightened to move!");
	query_current_attacker()->add_hp(-45);
    }
    return 1;
}
