#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Before the western town gates of Lodos");
    set_long("The great Lodos gates tower from the ground, directly above. "
      "To the west is an untamable mountain side and monsters waiting "
      "for the kill. To the east is the great town of Lodos, in all its "
      "peace and harmony.");
    set_items(([ "gates" : "The tall silver gates stand high above you"]));
    set_exits(([ "east" : ROOMS"wroad5",
	"west" : ROOMS"mount1"]));
    set_properties(([ "light" : 2, "town" : 1 ]));

}

void reset() {
    ::reset();
    if (!present("guard")) {
	new(MOB"gate_guard")->move(this_object());
	new(MOB"gate_guard")->move(this_object());
    }
}
