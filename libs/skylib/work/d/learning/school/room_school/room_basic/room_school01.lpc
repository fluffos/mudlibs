/**
 * Basic room school by Avelan
 * April 2001
 * Room #1
 */

#include "defs.h";
inherit ROOM_OBJ;

void setup(){
    set_light(100);
    set_determinate("the ");
    set_short("room school");

    set_long("Now, after taking the Unix lesson, you should know the commands "
        "to look how rooms are coded, and should from now on use the "
        "'more' command to see how the rooms here have been built.\n\n"
        "All the code will be commented and the functions in the rooms "
        "will be explained.  If at any point you feel that you need "
        "more info on some function, try help <function> to see if the "
        "help files contain information about it.  If that doesn't help, "
        "contact one of the more experienced creators.  Also, if there "
        "is something you would like to have here, contact "+
        CURRENT_LORD+" and let us know what is missing and we shall see "
        "what we can do.\n");

    add_exit("back", ROOMSCH+"start", "path");
    add_exit("forward", ROOMSC+"room_school02", "path");

} /* setup() */
