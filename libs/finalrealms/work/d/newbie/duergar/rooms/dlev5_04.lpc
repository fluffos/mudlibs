/*  Text alterations and additions by Grimbrand 2-11-96                 */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"ddwarf");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
   
   set_short("Realm of the Duergar:  Racial Proving Grounds");

   set_long("\n   Realm of the Duergar:  Racial Proving Grounds.\n\n"
            "     The room here is completely bare and unadorned.  The "
            "only things of note are the stains on the floor and the "
            "various chip marks upon the walls.  There is also however, "
            "a pool of blood upon the floor."
            "\n\n");

   add_item(({"floor", "stain", "stains"}),
            "   Looking at the floor you can see that the stone has been "
            "stained from the blood of battles long past.  This room must "
            "see a lot of traffic!  You also notice a fresh pool of blood "
            "on the floor as well."
            "\n\n");

   add_item(({"blood", "pool", "pool of blood"}),
            "   Looking at the blood, you can tell the battle was not too "
            "long ago, even now it is just barely starting to coagulate on "
            "the cool stone floor."
            "\n\n");

   add_item(({"wall", "walls"}),
            "   Looking at the wall, you can see where various weapons "
            "have left chip marks from wild swings and glancing blows."
            "\n\n");

   add_exit("north",NEWBIE+"dlev5_05","path");
   add_exit("south",NEWBIE+"dlev5_01","path");
}
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 
