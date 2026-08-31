#include <std.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("Domain of Shadows");
    set_long(
      "You have entered the Domain of Shadows. You see nothing but"
	" have the oddest feeling that you are being watched. There"
	" is a set of eyes looking at you for a second then they are gone"
	" into nothingness. "
    );
    set_items(([
        "eyes" : "A pair of glowing eyes",
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
    set_smell("default", "An odd smell of burning water is in the air.");
    set_listen("default", "The sound of a frustrated wiz beating his "

   "code is here");
    set_exits( ([
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );

}

