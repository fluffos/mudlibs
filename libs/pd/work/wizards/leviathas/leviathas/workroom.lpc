#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Leviathas' Workroom");
    set_long(
      "%^BOLD%^You are in a Silver workroom.  The walls "       "%^BOLD%^shimmer dully and have been tarnished by "
      "%^BOLD%^Leviathas's evil.%^RESET%^ ");
    set_items(([
        "room" : "The dorm room is rather drab looking.",
        "poster" : "1 : Type 'cd /wizards/(yourname)', this"
           " will change your current directory to your home directory."
  "\n2 : Type ls, this will give you a list of whats in your current
directory."
  "\n3 : Type 'more workroom.c', this will display the contents of "
  "this file."
  "\n4 : Now, be brave, and type 'ed workroom.c'.  As soon as you do this, "
  "type 'h', this will display a list of commands for the built in editor."
   "\nIf you need any more help, leave goto the hall from this room.",
   ({"wall", "the wall"}):
     "The wall has a poster on it, maybe you should look at it."
    ]));
    set_smell("default", "An odd smell of burning water is in the air.");
    set_listen("default", "The sound of a frustrated wiz beating his "         
"code is here");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
    
}
