//Modified by Ljen okt -96
// Coded By Joram 16 of August '96

inherit "/obj/monster";
#include "path.h"


void setup(){

   set_name("etriel");
   set_short("Etriel, Princess Of The Keep");
   set_long("Etriel, the oldest half-elf of the realms, has seen the "
            "beginning and end of the golden age for the elves, and was "
            "one of the first half-elven born.  She could tell you "
            "stories about your race, much of them glorious and other not so "
            "good.. Because although the green people, as is called in this "
            "place, is good aligned they had lots of problems with the other "
            "races. Specially with their dark cousins : The Drows.\n"
            "She is dressed in a beautiful dress, with silver linens"
	    " and patterns.\n");

   add_alias("princes");

   set_main_plural("Etriels, Princesses Of The Keep");
   add_plural("etriels");
   add_plural("princesses");

   set_gender(2);
   set_level(4);
   set_max_hp(40);
   set_race("half elf");

   add_clone("/d/newbie/half-elf/items/rdress", 1);

   load_chat(60,({
      1,"'Wonder if my time has come yet... suppose not when you are here",
      1,"@smiles sweetly at you",
      1,"@walks around the room with majesty",
      1,"'Have you seen all yet?",
      1,"'I retired here long ago, when the war between us and the drows got so cruel I couldn't life with it",
      1,"'Hmmmmmm........",
   }));

   load_a_chat(70,({
      1,"@exclaims: Seen you comming !!!, Thought this could only happend between drows !!!",
      1,"@yells: Protect me captain !!!",
      1,"@makes some magical gestures and a curse descends upon you",
   }));

}
   
