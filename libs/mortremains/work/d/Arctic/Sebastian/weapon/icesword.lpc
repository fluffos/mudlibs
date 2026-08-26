/*
** File: icesword.c duh.
** Date: June 17th, 1-triple 9
** Purpose: This is an ice sword, fear it.
** Other Notes:  Nope, first weapon I ever wrote, ain't ya proud?
**
*/


#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());

	set("author", "sebastian");

	set("name","icesword");

// This makes it what it is, the other types can be found in
// the dir /doc/properties
	set_weapon_type("sword/long");

// The material type can be anything, the default usually steel or
// wood
	set_material_type("ice");

// The "id" is all the things you can call it.
	set("id", ({ "sword", "icesword", "ice sword" }) );

//short is what you see when it's on the floor or in an inventory
// Make sure any "a" or "an" is lowercased!
	set("short", "an ice sword");

//long is what ya get when a player examines it
	set("long",@EndText
	This sword is made entirely of ice, with a hilt wrapped in fur.
EndText
	);

// bonus makes it a magical weapon, 1,2,3,4,5
// You can also do it like this set_bonus(1,1,1);
//   The first number makes it a +1 weapon
//   The second means it has a +1 to hit
//   The third means it has a +1 to damage
// In other words it is conceieveable that you could make a weapon
// that would have a +1 to hit and damage, but not be magical
// You would do that like this       set_bonus(0,1,1);
   set_bonus(1);
// "nosecond" set to 1 makes it a 2 handed weapon, 0 means you can have 
// another weapon wielded with it
   set("nosecond", 0);

//verbs are what you see when you attack. They are optional.
	set_verbs( ({ "slice", "slash", "impale" , "cut into" }) );
//verbs2 is what the other players in the room see
	set_verbs2( ({"slices", "slashes", "impales","cuts into" }) );

}
