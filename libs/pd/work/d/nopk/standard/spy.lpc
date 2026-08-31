#include <std.h>
#include <sindarii.h>

inherit ROOM;

void init() {
    ::init();
    add_action("read", "read");
}

void create() {
 ::create();
   set_properties(([
     "light" : 0, "night light" : -1, "town" : 1, "indoors" : 1, "tavern" : 1
   ]));
   set_short("The Spyder's Web");
   set_long("Spyder's Web is a dark underground tavern below Sun Alley. A "
     "stairway leads up, back onto Sun Alley and the surface. Thick smoke and "
     "mist fills the room. It is dark in this room below the surface of Tirun.");
   set_smell("default", "The Spyder's Web smells of tobacco smoke.");
   set_items(([
     "surface" : "A refuge from the outside world.",
     "tavern"  : "A dark tavern under the street.",
     "alley"   : "Sun Alley is accessable just up the stairs here.",
     "stairs"  : "Stairs lead upwards onto the streets of Tirun."
   ]));
   set_exits(([
     "up" : ROOMS"sun2"
   ]));
}

void reset() {
 ::reset();
   if(!present("tempest"))
     new(MOB"tempest")->move(this_object());
}

int read(string str) {
    object ob;
    int i;

    ob = present("tempest");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    message("info",
"\nThe menu reads:\n"
"-----------------------------------------------------\n"
"Spider Venom                                    "+ob->get_price("venom")+" gold\n"
"Black Wine                                      "+ob->get_price("wine")+" gold\n"
"Shot of Ontex                                   "+ob->get_price("shot")+" gold\n"
"Tempest's Rage                                  "+ob->get_price("rage")+" gold\n"
"-----------------------------------------------------",
this_player());
    return 1;
}
