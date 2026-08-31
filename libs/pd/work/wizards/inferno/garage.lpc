#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("A large garage");
   set_long("This is Inferno's garage. There is a rift at the far "
     "end of the room, in front of the garage door, leading to "
     "Sindarii square. Many different mounts are 'parked' here.");
   set_exits(([
     "north" : "/wizards/inferno/outfit",
     "out" : "/d/standard/square"
   ]));
}

void reset() {
 ::reset();
   if (!present("limo"))
     new("/wizards/inferno/limo")->move(this_object());
   if (!present("limo_keys"))
     new("/wizards/inferno/limo_keys")->move(this_object());
   if (!present("motorcycle"))
     new("/wizards/inferno/item/cycle")->move(this_object());
   if (!present("llama"))
     new("/d/lodos/obj/mon/llama")->move(this_object());
   if (!present("chariot"))
     new("/wizards/inferno/mount")->move(this_object());
}
