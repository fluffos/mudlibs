// Start room for getting-started
// October '01 by Avelan

#include "defs.h"
inherit ROOM_OBJ;

void setup(){

    set_short("start room");
    set_light(100);
    set_long("Ok, this section of the school will help"
      " you get started on creating a world of your own.\n\n"
      "The first exit leads you to information about the "
      "different ways of creating your files.  If you have"
      " no idea how to do it, you should take some time to learn.\n\n"
      "The second one will explain various things used every day"
      " by creators like 'call' or 'goto'.\n\nThe third will teach"
      " you how to use our wonderful ingame editing utility called ed.\n\n"
"And finally, the unix exit gives a list of unix commands for"
" handling files and directories.\n\n"
      "A quote from one of our elderly staff members is in order here:"
      " 'Remember, no-one was born with the knowledge on how to code!'\n");

    add_exit("creation", GETSTART "info" ,"path");
    add_exit("crecommands", GETSTART "basic_commands/cre_commands", "path");
    add_exit("edtutor", EDTUTOR "edtutor01","path");
add_exit("unix",UNIXTUTOR "unix","path");
    add_exit("back", SCHOOL "school", "path");

} /* setup() */
