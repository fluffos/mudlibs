#include <std.h>

inherit ROOM;

void init() {
 ::init();
   add_action("read", "read");
}

void create() {
 ::create();
   set_property("light", 2);
   set_property("indoors", 1);
   set_property("no attack", 1);
   set_property("no teleport", 1);
   set_short("Inferno's bar");
   set_long("%^BOLD%^%^BLACK%^"
     "You cannot make out much about this place. The walls, ceiling "
     "and floor are all painted black. A large silver disco ball sits in "
     "the center of the room. Music of all sorts plays loudly.");
   set_exits(([
     "south" : "/wizards/inferno/cafe"
   ]));
}

void reset() {
 ::reset();
   if(!present("voodoo")) 
     new("/wizards/inferno/voodoo")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("voodoo");
    if(!ob) {
	write("Voodoo can not be found.");
	return 1;
    }
    write(@ENDTEXT
The menu reads:
--------------------------------------------------------------------
A chalice of blood                               0 gold coins
A keg of whiskey                                 0 gold coins
A shot of ... universe                           0 gold coins
A bottle of wine                                 0 gold coins
--------------------------------------------------------------------
ENDTEXT);
    return 1;
}
