// Basic room school by Avelan
// April 2001
// room #2, the example.

#include "defs.h";
inherit ROOM_OBJ;


void setup(){

    set_light(100);

    set_short("basic room school");

    set_determinate("the ");

    set_long("This is a room which describes how a very"
      " basic room is built.  The room is quite small and"
      " rather empty since there is only a table and a small"
      " chair standing in the middle of the room.  There is"
      " some writing on the table probably made by a bored"
      " apprentice creator trying to learn things.\n");


    add_item("room","The room looks quite empty.");
    add_item(({"creator","apprentice","apprentice creator"}),
      "They are the ones that are learning new stuff, this room"
      " is built for them.");
    add_item("thing","There are many things to learn here.");
    add_item("chair",({ "long","The chair is old and worn"
        " out, it's been under heavy use.","position","the chair"}));
    add_item("table",({ "long","The table is an ordinary, round,"
        " wooden table, it has some writing on it.",
        "position","the table"}));
    add_item("writing",({ "long","There is some writing on the"
        " table, You could read it if you want to.",
        "read","I'm so booooreeed!\n" }));


    add_exit("back",ROOMSC "room_school02","path");


} /* setup */
