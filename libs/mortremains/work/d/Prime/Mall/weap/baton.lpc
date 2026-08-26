/*
** File: baton.c
** Purpose: a weapon for the security guards at the mall.
**  Credits:
**   July 5, 2000 Herself
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("club");
    set("id" , ({"baton"}) );
    set("short" , "a baton");
    set("long", 
      "It is a security guard's baton.\n");
    set("name" , "baton");
    set("nosecond", 0);
    set("value" , 35);
    set("mass" , 3);
    set_verbs( ({"hit at" , "pound on" , "beat on"}) );
}     

/* End of File */
