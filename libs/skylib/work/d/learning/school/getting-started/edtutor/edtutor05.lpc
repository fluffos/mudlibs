// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 5");
  set_long("   Lastly there is the <w> command.  This "
      "saves the file you are working on but does not "
      "exit you from ED.  Again if you are working on "
      "a file with no name, you must type <w file_name.c> "
      "and then <q>.  Then re-enter the file with "
      "<ed file_name.c>.  At this time you can just type <w> or "
      "<x> and the computer will know what name to save your file "
      "under.\n");

  add_exit("south",EDTUTOR "edtutor04","path");
  add_exit("north",EDTUTOR "edtutor06","path");
}
