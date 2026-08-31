#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();                     

set_name("east of town square");
set_items((["dirt"  : "A light brown mixture ",
            "church"  : "The large white church glows with holyness"])); 
set_properties((["light":2 ,"night light":3]));
set_short("A dirt path");
set_long("You are standing right in front of the large "
         "white Church. the snow is no where to be found. "
         "The Church lights up the hole room.");

set_exits( ([ "enter" : ROOMS "Church",
              "west" :  ROOMS "roston21" ]));
}                                             
