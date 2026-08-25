/*   Text upgrade and rewrite by Grimbrand 2-1-96                   */

#include "path.h"
inherit "/std/underground";

object *npcs;

/*
void reset() {
int i;
 for(i=0;i<sizeof(npcs);i++) {
  if(!npcs[i]) {
  npcs[i]=clone_object(DNPC+"dmaster01");
  npcs[i]->move(this_object());
  }
 }
}
*/

void setup() {
  add_property("no_undead",1); set_light(10);
  npcs = allocate(1);
set_short("Realm of the Duergar:  Mine Masters Office");
set_long("\n   Realm of the Duergar:  Mine Masters Office.\n\n"
         "     You have entered the Mine Masters Office.  All around the "
         "room you can see the various types of mining equipment and "
         "ore typical to what can be found in the mines of Dendall.  "
         "Behind the Masters desk a large assortment of picks, hammers, "
         "and spikes can be seen neatly laid out for display.  Along "
         "the other three walls, nicely arranged, lie the different "
         "yet typical ore commonplace in Dendall.  Among them, some "
         "of the most beautiful crystalline formations you have ever "
         "seen catch your eye.  The Mine Master sits down behind his "
         "desk and eyes you over as you drool over his prize collection.  "
         "It would be a good idea to \"listen\" to him and what he "
         "has to say.\n"
         "\n");

add_item("picks","   You look at the various sizes of picks on the wall "
	 "behind the Masters desk, and wonder why there are so many.  "
	 "There are even some that you are not sure you could "
         "lift.  One detail that does leave a good impression upon "
         "your mind is the excellent condition they appear to be "
         "in.\n");

add_item("hammers", "   The hammers on the wall behind the desk have "
         "been arranged according to size.  The variety of hammer "
         "types are so varied and strange you question whether or "
         "not some of them are even hammers.  They are all in "
         "excellent shape.\n");

add_item("spikes", "   On the wall next to the hammers are these "
          "spikes.  Without these simple pieces of metal the hammers "
          "are rendered almost useless for mining purposes.  For the "
          "most part all of the spikes are standardized in shape and "
          "vary only in size.\n");

add_item(({"ore", "ores", "rock", "rocks"}),
         "   The various ore types have been sorted and placed along "
         "the walls of the room.  Each wall has been dedicated to a "
         "specific theme, one wall is metal types, another is crystal "
         "formations, and the last is precious natural treasures.\n");

add_item("gems", "   You see a wide variety of all the known gems in "
          "the realms.  Handsomely displayed in a sturdy metal case "
          "with thick glass, it is obvious they represent great "
          "wealth and mining expertise.\n\n"
          "Helden eyes you closely, hefting a wicked looking pick.\n");

add_exit("up",NEWBIE+"main03","door");
add_exit("west",NEWBIE+"dlev1_01","door");
modify_exit("west",({"function","bouncer"}));
add_clone(DNPC+"dmaster01",1);
}

/*
void dest_me() {
int i;
for(i=0;i<sizeof(npcs);i++)
  if(npcs[i]) npcs[i]->dest_me();

 ::dest_me();
}
*/
 
int bouncer() {
int lv,xp;
object me = this_player();
lv = (int)me->query_level();
xp = (int)me->query_xp();
if(lv == 1 && xp <4000) {
write("   The door opens easily when you push it, allowing you to "
      "enter the area beyond.\n\n");
tell_room(environment(me), me->query_cap_name()+" steps towards the "
	 "door and it opens quietly, allowing "+me->query_cap_name()+
	 " to enter.\n",({this_player()}));
    return 1;
}
notify_fail("   You walk into the door attempting to push it open.\n\n");
tell_room(environment(me), me->query_cap_name()+" walks into the west "
          "door and rebounds with a hurt and surprised look upon "
          +me->query_possessive()+" face.\n\n", ({ this_player() }));
return 0;
}
