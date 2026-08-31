#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("The outfitting room");
   set_long("A long white room with racks of equipment and armour "
     "lined up horizontally across the room. To the north is Inferno's "
     "workroom. The sky swirls a dark grey, and lightning streaks "
     "across they sky.");
   set_exits(([
     "north" : "/wizards/inferno/workroom",
     "south" : "/wizards/inferno/garage"
   ]));
}

int ready() {
   write("You are mystically readied.");
   if (!present("platemail", this_player()))
     new("/wizards/inferno/item/foo")->move(this_player());
   if (!present("oi", this_player()))
     new("/wizards/inferno/oivay")->move(this_player());
   if (!present("knuckles", this_player()))
     new("/d/lodos/obj/weapon/knuckles")->move(this_player());
   if (!present("infhammer", this_player()))
     new("/wizards/inferno/item/hammer")->move(this_player());
   return 1;
}

void init() {
 ::init();
   add_action("ready", "ready");
}
