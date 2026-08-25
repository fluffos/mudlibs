/*  Text alterations and additions by Grimbrand 2-3-96                   */

#include "path.h"
inherit "/std/underground";

object *npcs;

void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"ddrider");
  npcs[i]->move(this_object());
  }
 }
}

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);

   set_short("Realm of the Duergar:  Cavern Proving Grounds");

   set_long("\n   Realm of the Duergar:  Cavern Proving Grounds.\n\n"
            "     Dark and musty, this cavern reminds you of your days "
            "as a child.  Days of endless wandering through the caverns "
            "searching for food, water, and a safe place to sleep.  Now "
            "at least you have a weapon, but you also realize there are "
            "things here, somewhere, that will try to kill you.  You "
            "almost feel as if you are trapped in a maze full of hostile "
            "occupants ready to kill or be killed.  The rooms walls are "
            "rough and unevenly hewn, and a phosphoresent moss growing "
            "upon the stone is the only source of light.  Upon the floor "
            "your fears are reinforced as you note freshly spilt blood "
            "slowly coagulating in the cool surroundings.\n"
            "\n");

   add_item("floor",
            "   Dark and old stains have given a mottled look to the "
            "stone, but they are far too old to determine what it was "
            "that caused the stains.\n\n");

   add_item("blood",
            "   Freshly spilt it seems, someone passed through here "
            "recently, hopefully when you run into them they will be "
            "easily overcome.\n\n");

   add_item(({"wall", "walls", "rock", "rocks"}),
              "   Roughly cut, the walls were obviously hewn quickly "
              "with only utilitarian intentions in mind.\n\n");

add_exit("north", NEWBIE+"dlev4_03", "path");
add_exit("south", NEWBIE+"dlev4_05", "path");
add_exit("east", NEWBIE+"dlev4_08", "path");
add_exit("west",NEWBIE+"dlev4_01","path");
}
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
 
