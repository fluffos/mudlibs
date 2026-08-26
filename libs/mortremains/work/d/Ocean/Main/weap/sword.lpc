/*
** File: sword.c
** Purpose: a weapon
** Credits: Created by Herself on July 25, 2000
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("sword/long");
    set("id" , ({"nose" , "sword" , "swordfish" , "swordfish nose"}) );
    set("short" , "the nose of a swordfish");
    set("long" , wrap(
	"The sharp pointed nose of a swordfish. It "+
	"might make for a handy weapon. "
      ));
    set("name" , "swordfish");
    set("nosecond", 0);
    set("value" , 15);
    set("mass" , 7);
    set_verbs( ({"slash at" , "swipe at" , "stab at"}) );
    set_verbs2( ({"slashes at" , "swipes at" , "stabs at"}) );
}     

/* End of File */
