// Basic room school by Avelan
// room #3, example
// May 2001

#include "defs.h";
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


    room_chat(({ 120, 240, ({
          "A leaf falls off from one of the trees.",
          "A bird flies by and vanishes in one of treetops.",
          "Wind rustles the leaves a bit.",
          "A bird catches an ant running up the tree."
        }) }) );

    add_exit("back",ROOMSC "room_school03","path");

}
