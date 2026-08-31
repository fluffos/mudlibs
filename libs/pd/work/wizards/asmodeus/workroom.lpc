
#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
set_short("%^MAGENTA%^The %^BOLD%^YELLOW%^throne%^RESET%^MAGENTA%^ room%^RESET%^");
set_long("You have entered the throne room of %^BOLD%^RED%^Asmodeus%^RESET%^, the %^BOLD%^RED%^Demon Lord%^RESET%^.  He waits here patiently while plotting the fall of man and constructing the devices and measures with which to complete his twisted goals.  The %^MAGENTA%^winds of evil%^RESET%^ trap your soul from the protection of %^CYAN%^BOLD%^God%^RESET%^.");
    set_items(([
        "room" : "The dorm room is rather drab looking.",
        "poster" : "1 : Type 'cd /wizards/(yourname)', this"
           " will change your current directory to your home directory."
  "\n2 : Type ls, this will give you a list of whats in your current directory."
  "\n3 : Type 'more workroom.c', this will display the contents of "
  "this file."
  "\n4 : Now, be brave, and type 'ed workroom.c'.  As soon as you do this, "
  "type 'h', this will display a list of commands for the built in editor."
   "\nIf you need any more help, leave goto the hall from this room.",
   ({"wall", "the wall"}):
     "The wall has a poster on it, maybe you should look at it."
    ]));
set_smell("default", "The stench of burning flesh consumes the air.");
set_listen("default", "You hear the screams of tortured souls as they burn eternally.");
    set_exits( ([ 
    ]) );
    
}
