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
     "light" : 2, "town" : 1, "indoors" : 1, "tavern" : 1
   ]));
   set_short("The dull and rusty");
   set_long("This is the dull and rusty tavern. Smoke fills the air, "
     "making it just as hard to see whether it happens to be night or "
     "day. There are no windows and the door leading out is always "
     "closed. A menu has been hung up on the wall.");
   set_items(([
     "smoke" : "Tobacco smoke fills the air.",
     "foo" : "bar",
     "door" : "The patrons always close the door on their way out.",
     "menu" : "You could probably read it.",
   ]));
   set_exits(([
     "out" : ROOMS"sun2"
   ]));
}

void reset() {
 ::reset();
    if(!present("dexter")) 
      new(MOB"dexter")->move(this_object());
    if(!present("drunk")) {
      new(MOB"drunk")->move(this_object());
      new(MOB"drunk")->move(this_object());
    }
}

int read(string str) {
    object ob;
    int i;

    ob = present("dexter");
    if(!ob) {
        write("You cannot read the menu, as it is splattered with blood.");
	return 1;
    }
    message("info",
"\nThe menu reads:\n"
"-----------------------------------------------------\n"
"Whiskey Sour                                    "+ob->get_price("whiskey")+" gold\n"
"Wattered Down Ale                               "+ob->get_price("ale")+" gold\n"
"A Pretzel                                       "+ob->get_price("pretzel")+" gold\n"
"A Glass of Spirits                              "+ob->get_price("spirits")+" gold\n"
"The House Special                               "+ob->get_price("special")+" gold\n"
"-----------------------------------------------------",
this_player());
    return 1;
}
