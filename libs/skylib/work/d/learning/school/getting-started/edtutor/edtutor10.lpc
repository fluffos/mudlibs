// May's Ed Tutorial for Wizards
// brought to FF on 5 Feb 2001
// brought to Riftwar and modified to work here 7/02/01 - Shaydz

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
  set_light(80);
  set_short("Ed Tutorial 10");
  set_long("   The SUBSTITUTE command may be THE most "
    "important command that you will learn in ED.  It "
    "is the command that you use to change text on a "
    "single line.  This is important because this command "
    "saves you from having to type over an entire line.  Lets "
    "say that you have a line that starts off:  set_logn(... "
    "and you want to change it to set_long(...  What you would "
    "type is <s/logn/long>.  This SUBSTITUTES in 'long' for 'logn'."
    "  You need not use front slashes between the 2 strings "
    "being changed.  You can use any character as long as you "
    "only use one single character.  For example, we can write "
    "out the first example as <s!logn!long>.  This will accomplish "
    "exactly the same thing.\n   This is important when you are working "
    "with text of directories, text that has a frontslash in it.  "
    "You would not want to use the frontslash so you could use "
    "<s!/name/dir!/name/dir2>.  In this case, the '!' is the "
    "character that divided the strings and the slash is used "
    "in the string.  You may also want to use the 's' command "
    "over a set number of lines.  In that case you would "
    "write <1,25s/str1/str2>.  This will change the first occurance "
    "of str1 on each line to str2.  If you want to change ALL "
    "occurances of str1 to str2 you would have to add an extra "
    "'g' command to the original text so it would look like "
    "this: <1,25s/str1/str2/g>.\n");

  add_exit("south",EDTUTOR "edtutor09","path");
  add_exit("north",EDTUTOR "edtutor11","path");
}
