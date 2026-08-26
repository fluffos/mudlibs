/*
** File: spear.c
** Purpose: a weapon
** Credits: Created by Herself on July 25, 2000
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("spear");
    set("id" , ({"spear"}) );
    set("short" , "a spear");
    set("long" , wrap(
	"A long handled weapon, used for killing whales "+
	"or other fish. "
      ));
    set("name" , "spear");
    set("damage_type" , "piercing");
    set("nosecond", 0);
    set("value" , 15);
    set("mass" , 7);
    set_verbs( ({"stap at" , "poke at" , "lunge at"}) );
}     

/* End of File */
