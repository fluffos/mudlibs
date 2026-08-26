/* File: rcloak.c 
**  Purpose: You figure it out, duh...
**  Date: July 30th, 1997
**  Yet another random note: Bite me.
**  Credits: Nightmask the Fresh Breaker.
*/

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
  void create() {
   set("short", "leather armour");
//short is what you see w/o an examine
   set("long", @Suckme
Leather armor, you could like wear it, dosen't look too cool, but what
do you expect for free. :)
Suckme
 );
//long is what is seen when the object is examined. the @SuckMe
//statement allows you to write a long description without useing
// n\"+ all the time
   set("id", ({ "leather", "leather armour", "armour" }) );
//this allows a player to exa the item in more ways than 1
   set_armor_type("leather");
//armor_type makes it a type of armor, thew other types can be found
//in /doc/properties
}
