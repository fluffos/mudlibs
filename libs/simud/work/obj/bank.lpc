#include <inven.h>
#include <desc.h>
#include <object.h>

/** This is the "inventory bank." The reason for its existence is to make
 * sure that player inventories stay active (i.e. the objects still exist
 */

/** Initialize the inventory bank to its default values.
 */
create() {
/* OBJEDIT { */
   set_long("The inventory bank, a vast tract of extra-dimensional space, "+
            "surrounds you. Scattered throughout this place are many force "+
            "bubbles, floating in space. Each bubble contains small piles of "+
            "possessions -- swords, books, trinkets, and all kinds of "+
            "worthless junk. Every now and then a new bubble appears or one "+
            "disappears, as their owners enter and leave the world.\n\n"+
            "Truly, this is a place that only a wizard may fully understand. "+
            "Frankly, if you're NOT a wizard, please poke one and tell them "+
            "how you got here.");
   set_short("The inventory bank");
   set_name("bank");
/* } OBJEDIT */
   ::create();
}

/* A customized override of Inven::save_self() -- this will empty all
 * player inventories into the bank before saving, then restore the
 * inventories when done. The reason for this is so that if the MUD
 * crashes or is otherwise shut down abnormally, the bank will have
 * saved itself in a state where all the player inventories are
 * recorded, and the players that were logged on when the save occurred
 * will have their inventories restored as expected.
 */
void save_self() {
   object player, ob;

   foreach( player : users() )
      player->make_bubble();

   ::save_self();

   foreach( player : users() )
      player->restore_bubble();
}

void presave() {
   object player;

   foreach( player : users() )
      player->make_bubble();
}

void postsave() {
   object player;

   foreach( player : users() )
      player->restore_bubble();
}
