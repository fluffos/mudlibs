// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 3");
  set_long("   The P and L commands are used to show you what code "
    "you have written so far.  P shows you the general code and L "
    "shows you everything that P shows you, but also includes the "
    "control characters that may be hidden in the code.\n   Since "
    "all commands here on the mud are case-sensitive, you have to "
    "type lower case p's and l's, otherwise the computer won't recognize "
    "the commands.  Now, to see a line specifically by number, you "
    "can type #p and that will show you the line # with out any of "
    "the hidden characters.  If you want to see a range of lines, "
    "you can add in a <,> between two numbers like <1,15p> to show "
    "you lines 1 through 15. The same holds true for the l command "
    "except you will also see hidden characters.\n   Now you already "
    "know the <.> means current line from the last room, so if you "
    "type <1,.l> that will show you all the lines starting at 1 "
    "and ending at your current line.  Another important symbol is "
    "the <$>.   That means <last line>.  So, if you wanted to "
    "see all the lines in a single file, you would type <1,$p> or "
    "1 through last line, print.\n   Now that you can see all the "
    "lines of your files, you are ready so see how to save them so "
    "you can get out of ed.\n");

  add_exit("south",EDTUTOR "edtutor02","path");
  add_exit("north",EDTUTOR "edtutor04","path");
}
