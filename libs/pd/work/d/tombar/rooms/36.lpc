// Coded by Whit
#include <std.h>
#include <tombar.h>
inherit ROOM;
void create() {
    ::create();
    set_name("a long, black hallway");
   set_long("This room doesnt seem to fit with the rest of the temple.  "
      "There is a small stone pedistal in the middle of the carpeted and "
      "dimly lit room.  Arcane spells are written all over the walls in "
      "this room.  You feel a strange power emanating from the walls.  ");
    set_items(([
	"spells" : "The spells are in an unknown language.  Perhaps a forgotten language."
      ]));
    set_exits(([
	"north" : ROOMS"34",
      ]));

}

void reset() {
    ::reset();
    if(!present("pedistal")) {
	new(OBJ"pedistal2")->move(this_object());
    }
}

