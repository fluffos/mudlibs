#include "path.h"

inherit "/std/bank";
//inherit "/std/room";

void setup() 
  {
   set_light(80);
   set_short("Daggerford bank");
   set_long("You are in Daggerford Bank. The bank is filled with friendly "+
      "looking people, standing behind a polished bench, eagerly awaiting "+ 
      "the pleasure of serving you. There is a sign hanging on the "+
      "wall.\n");
   
   add_exit("south", ROOM+"mark1", "door");
   
   add_item("bench", "A nice shiny bench made of the best oak.  It looks "+
      "very expensive and fits in with the rest of the plush "+
      "atmosphere of the room.\n");
   add_item(({ "teller", "people" }),
      "A nice happy looking bunch of tellers.  They look "+
      "happy and will to serve.  They don't look predatory "+
      "at all.\n");
   add_item("wall", "They are amazingly lush.  You are surprised they are "+
      "not carpeted.\n");
   add_item("floor", "Polished wooden floor boards.  You look around for the "+
      "cleaning ladies who are going to clean up your foot "+
      "prints.\n");
   
   add_sign("A small happy sign.\n",
      "Welcome to Daggerford Bank.\nThe commands are "+
      "\"open\" an account, \"close\" an account, \"deposit\" some "+
      "money, \"withdraw\" some money and get a \"balance\".  Please "+
      "note we charge 5% on deposits.\n");

   //add_sign("Because of disagreements, the tellers won't let you use this " +
   //         "bank. We are sorry for the inconvenience.\n");
   set_percentage(95);
   set_save_file(ROOM + "bank");
}
