// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 6");
  set_long("   The add and insert commands <a> and <i> "
      "are quite similar.  They both put you in to the "
      "'add text' mode.  The difference between the 2 "
      "commands is where the new text will be placed.  "
      "When using the <a> command, the new lines are put "
      "AFTER the specified line.  If no line # is given, "
      "then the text is put after the CURRENT line.  The "
      "<i> command works similarly but the text is INSERTED "
      "BEFORE the specified line.  The same holds true if "
      "no line number is given.\n   To get out of the 'add "
      "text' mode, type a <.> and Ed will put you back in "
      "the reqular editing mode.\n   Now, when a file is "
      "opened for the first time and no texts exists in the "
      "file, just type <a> and start to add to the file.  "
      "Remember to type <w file_name.c> to save it when you "
      "are ready.  Then type <q> to get out of ED.  Re-enter "
      "ED with <ed file_name.c> and you are ready to edit your "
      "file.\n");

  add_exit("south",EDTUTOR "edtutor05","path");
  add_exit("north",EDTUTOR "edtutor07","path");
}
