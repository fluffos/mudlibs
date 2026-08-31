#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "forest" : 1]) );
    set_short("Direwolf's Forest");
    set_long(
      "This is a slight clearing in Direwolf's forest.  "  
      "THere are many tall, coniferous trees and everything looks"
      " very green and healthy.  There is a cabin here with smoke"
      "rising from the chimney.  It looks quite cozy.  There is a "
      "stack of oak wood supplying inhabitants.  There is a poster "
      "on the side of the cabin.  A little glass case with an undying"  
      "Rose is here with the words 'Jade' scrawled"
      "in gold."
    );
    set_items(([
        "forest" : "The forest is green and well taken care of by Direwolf.",


        "poster" : "1 : Type 'cd /wizards/(yourname)', this"
           " will change your current directory to your home directory."
  "\n2 : Type ls, this will give you a list of whats in your current
directory."
  "\n3 : Type 'more workroom.c', this will display the contents of "
  "this file."
  "\n4 : Now, be brave, and type 'ed workroom.c'.  As soon as you do this, "
  "type 'h', this will display a list of commands for the built in editor."
   "\nIf you need any more help, leave goto the hall from this room.",
   ({"cabin", "the cabin"}):
     "The Cabin looks warm and cozy. It has a poster on it, maybe you should
look at it."
    ]));
    set_smell("default", "The fresh scent of pine trees and burning oak is in
the air.");
    set_listen("default", "Small animals scurrying about and birds chirping
peacefully can be heard. "         
"code is here");
    set_exits( ([ 
        "square" :  "/d/tirun/square",
        "hall"  :  "/d/standard/adv_inner",
        "ranger" : "/d/tirun/fighter/ranger/ranger_hall"
    ]) );

}
