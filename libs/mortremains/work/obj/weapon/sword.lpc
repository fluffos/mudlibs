/*
**  File: example_sword.c
**  Purpose : This is the standard example weapon, heavily commented
**      for learning purposes.
**  Credits:
**    15 Jun 97    Cyanide created the file and commented ALOT.
*/

// This line is an example of a one-line comment.

#include <mudlib.h>      //This is very important...

// The next line tells the mud you're making a weapon.
inherit WEAPON;

void create() {
  seteuid(getuid());
// This line tells us who coded the item.
  set("author", "cyanide");

// This function makes it a long sword. It sets the mass, damage,
// value, and material of the item. Always call this towards the
// top of the create() function.
  set_weapon_type("sword/long");

// The "id" is a list of all the names that somebody can use to refer
// to the item.
  set("id", ({ "sword", "longsword", "weapon", "long sword",
      "steel long sword" }) );

// This is the name of the item, as it appears in your inventory.
// Make sure it's in lower case!
  set("short", "a fine steel long sword");

// This is the description of the item, for when you examine it.
  set("long", 
"This is a finely crafted weapon of what appears to be elvish\n"+
"design. It is perfectly balanced and is razor sharp.\n" );

// The "name" is the name which the weapon is referred to in combat.
  set("name", "fine long sword");

// This sets the weapon to a +1 magical bonus.
  set_bonus(1);

// If "nosecond" is set to 1, then the weapon must be used in two hands.
  set("nosecond", 0);

// Setting "light" to 1 makes an object glow. It becomes an effective
// light source.
  set("light", 1);

// The "verbs" are the verbs you use in combat whenever you swing.
  set_verbs( ({ "swing at", "hack at", "cut" }) );
  set_verbs2( ({ "swings at", "hacks at", "cuts" }) );
}     

/*    This an example of a long comment...

  Please add to the top of your code your name and the date you
  created the item.  If possible, also add the purpose for which
  the item was created.

  If you have any questions or comments, plese mail Cyanide...
      (He likes mail - honest).

Close a long comment with this ----->      */

/* End of File */
