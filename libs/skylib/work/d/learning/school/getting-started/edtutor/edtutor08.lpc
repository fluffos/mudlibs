// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 8");
  set_long("   The <c> command is for CHANGE.  This command "
    "combines the <d> command and the <a> command into one "
    "command.  What this command does is delete the specified "
    "lines and then put you in to 'add mode'.  For instance, "
    "if you wanted to change the text in a line and it was too "
    "much to 'substitute' for, and it was on line 10, you could "
    "write <10c>.  That would get rid of line 10 and put you "
    "in 'add text' mode at line 10.\n   You can also delete "
    "multiple lines by using the comma.  For instance, you could "
    "get rid of lines 1-5 and begin to add text by typing <1,5c>.\n");

  add_exit("south",EDTUTOR "edtutor07","path");
  add_exit("north",EDTUTOR "edtutor09","path");
}
