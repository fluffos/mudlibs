#include <std.h>
inherit ARMOUR;

int guildbond();

void create() {
    ::create();

    set_name("helmet");

    set_short("%^BOLD%^RED%^Ka%^RESET%^BOLD%^bu%^RESET%^BOLD%^RED%^to%^RESET%^");

    set_long("An ancient mask belonging to a long forgotten tribe, the Kabuto "
      "has a large red mane and bright red paint encircling the eyes.");

    set_id(({"kabuto", "helmet", "helm"}));

    set_ac(4);
    //Set this to the highest it will be approved
    set_weight(0);

    set_curr_value("gold", 300 + random(150));

    set_wear( (: guildbond :) );

    set_remove("The music stops, the spirits drift back into nothingness.");

    set_type("helmet");

    set_limbs(({"head"}));

    //  set_property("magic item", ({"guildbond"}));

}

int guildbond(){
    if(this_player()->query_guild()!="AoD"){
	write("Your ears begin to bleed as you attempt to"
	  " wear the kabuto. \n");
	return 0;
    }
    write("As you don the kabuto the spirits of an old generation of warriors"
      " take over your body and you begin to dance!");
    return 1;
}

int query_auto_load() {
    if(this_player()->query_guild() == "AoD" )
	return 1;
}
