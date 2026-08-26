/*
** File: scissors.c
** Purpose: a weapon for the security guards at the mall.
**  Credits:
**   July 5, 2000 Herself
*/


#include <mudlib.h>

inherit WEAPON;

void create() {
    seteuid(getuid());
    set("author" , "herself");
    set_weapon_type("knife");
    set("id" , ({"scissors" , "sewing scissors"}) );
    set("short" , "sewing scissors");
    set("long" , wrap(
	"A pair of sewing scissors. They are sharper than "+
	"normal scissors, because they have to cut through "+
	"cloth. ") );
    set("name" , "scissors");
    set("nosecond", 0);
    set("value" , 20);
    set("mass" , 2);
    set_verbs( ({"stab at" , "poke at" , "slash"}) );
    set_verbs2( ({"stabs at" , "pokes at" , "slashes" }) );
}     

/* End of File */
