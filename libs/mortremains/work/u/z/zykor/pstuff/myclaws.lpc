
#include <mudlib.h>      //This is very important...

inherit WEAPON;

void create() {
  seteuid(getuid());
// This line tells us who coded the item.
set("author", "zykor");

// This function makes it a long sword. It sets the mass, damage,
// value, and material of the item. Always call this towards the
// top of the create() function.
set_weapon_type("dagger");

// The "id" is a list of all the names that somebody can use to refer
// to the item.
set("id", ({ "claws" }) );

// This is the name of the item, as it appears in your inventory.
// Make sure it's in lower case!
set("short", "adamantium claws");

// This is the description of the item, for when you examine it.
  set("long", 
"This is a finely crafted weapon of what appears to be elvish\n"+
"design. It is perfectly balanced and is razor sharp.\n" );

// The "name" is the name which the weapon is referred to in combat.
set("name", "adamantium claws");

// This sets the weapon to a +1 magical bonus.
set_bonus(666);

// If "nosecond" is set to 1, then the weapon must be used in two hands.
set("second",1);
  set("nosecond", 0);

// Setting "light" to 1 makes an object glow. It becomes an effective
// light source.
  set("light", 1);

// The "verbs" are the verbs you use in combat whenever you swing.
  set_verbs( ({ "swing at", "hack at", "cut" }) );
  set_verbs2( ({ "swings at", "hacks at", "cuts" }) );
}     


/* End of File */
