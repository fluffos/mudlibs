#include <std.h>
inherit ARMOUR;

void create() {
    ::create();
    set_name("Adimantite Armour");
    set_short("Adimantite Armour");	
    set_long("This armour is made of a metal that has no roots in"
	" this realm. There are some scratches but some nicks on it"
	" showing it has been to battle with no damage. It must be"
	" made by a very skilled smith.");
    set_id( ({ "armour" , "adimantite armour","adimant armour" }) );
    set_wear("%^BOLD%^You feel overly protected with this.");
    set_remove("%^BOLD%^QUICK!!! COVER UP YOURSELF!");
    set_ac(10);
    set_mass(55);
    set_curr_value("gold", 60);
    set_type("body armour");
    set_limbs( ({ "torso","head","right arm","left arm"
}) );

}

int query_auto_load()
{
 if (wizardp(this_player())) return 1;
 return 1;
}
