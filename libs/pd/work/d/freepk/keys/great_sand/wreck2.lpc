#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_short("In the ruins of a ship");
   set_long("This part of the ship is too badly damaged to really be "
	"able to see what it once was. Wooden planks are scattered "
	"around everywhere, as well as poles and other rubble.");
   set_items(([
   ]));
   set_exits(([
	"south":"/d/freepk/keys/great_sand/wreck"
   ]));
}

void reset() {
   if (!present("sailor")) {
     new("/d/freepk/keys/great_sand/sailor")->move(this_object());
     new("/d/freepk/keys/great_sand/sailor")->move(this_object());
   }
}
