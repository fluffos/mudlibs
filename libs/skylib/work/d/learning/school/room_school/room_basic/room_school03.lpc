// Basic room school by Avelan
// room #3
// May 2001

/*
* NOTE: In order to avoid confusion and to make
* these files a bit easier to read, i'll only
* comment those functions that i haven't commented
* before in the school.
*/

#include "defs.h";

/* Remember that we inherited ROOM_OBJ in the last room
* that you were in.  Just like that one, OUTSIDE_OBJ points
* to a file, help global defines to see which one.  The
* difference between the two, as you might have guessed, is
* that ROOM_OBJ is an inside room and OUTSIDE_OBJ is an outside
* one.  They have a few differences, but the main one is that
* OUTSIDE_OBJ rooms are affected by the weather.
*/

inherit OUTSIDE_OBJ;

void setup(){
    set_light(80);
    set_short("outside room");
    set_determinate("an ");
    set_long("This room describes what a basic outside room"
      " is like.  A few trees grow here and there are some nests"
      " embedded deep within their branches.  The branches are"
      " almost as big as smaller trees and could easily hide"
      " a few small animals, this makes the trees excellent"
      " hiding places for animals.\n");

    /*
    * Next the add_items, note that the plurals are handled
    * automatically, so i only need to make an add_item for
    * nest and still 'look at nests' works also.
    */
    add_item(({"room","outside room"}),"The room is quite"
      " plain, only a few trees are here.");
    add_item("tree","The trees are quite tall and have"
      " huge branches.");
    add_item("branch","The branches are huge, there are some"
      " nests on them.");
    add_item("nest","The nests obviously belong to some small"
      " birds.");
    add_item("bird","None are visible at the moment.");
    add_item("animal","There must be many animals living in"
      " these trees, although you don't see any right now.");
    add_item(({"place","hiding place"}),"The trees must be"
      " excellent hiding places for animals.");
    add_item("leaf","The leaves rustle in the wind every once in"
      " a while.");
    add_item("ant","There are ants running up and down the trees.");
    add_item("treetop","The treetops are hiding several birds judging"
      " from the beautiful singing that can be heard.");

    /*
    * Ok, a new function called room_chat.  You should use
    * these in most of the rooms you make, both inside and outside.
    * They make the rooms much more interesting.  The numbers
    * in the function are times, a new chat is chosen between those
    * times, so atleast 120 seconds after the last chat but also before
    * 240 seconds have past.
    * NOTE: Also the nouns in the room chats should have an add_item.
    */
    room_chat(({ 120, 240, ({
          "A leaf falls off from one of the trees.",
          "A bird flies by and vanishes in one of treetops.",
          "Wind rustles the leaves a bit.",
          "A bird catches an ant running up the tree."
        }) }) );

    add_exit("backward",ROOMSC "room_school02","path");
    add_exit("forward",ROOMSC "room_school04","path");
    add_exit("example",ROOMSC "example02","path");
}
