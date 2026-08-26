/*
** FILE: obsword.c
** PURPOSE: Example of set_bonus() function.
** CREATOR: Cyanide@Nightfall's Keep
** CHANGES:
**    9 Apr 97    Cyanide    Created the file.
**   18 Jun 97    Cyanide    Updated the weapon to include the new
**                           set_weapon_type function.
*/

#include <mudlib.h>

inherit WEAPON;

void create() {
  set_weapon_type("dagger") ;
	set("id", ({ "fork" }) );
set("value",   1000);
  set("short", "a fork") ;
	set("long", @LONG
A sharp, pointy fork.  Not exactly a deadly weapon.
LONG
	);
  set("name", "fork") ;
  set_verbs( ({ "attack", "poke at", "stab at" }) );
  set("damage", ({ 1, 2}) );
  set("value", 10 ) ;
}

