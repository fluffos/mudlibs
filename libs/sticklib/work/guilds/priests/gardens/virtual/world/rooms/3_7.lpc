/* Entrance to the gardens of Boccob */

#include "../gardens.h"
#include <virtual_room.h>

int gates_shut;

void
create_virtual() {
    X = 3;
    Y = 7;
    set(ROOM_WD, WD_OUTDOORS);
    set(SKIP_EXITS);
    set_light_level(LT_LIGHTS);

    set_short("High cliff overlooking a large basin");
    set_long("Surely this must be the fabled Gardens of Boccob - here \
Clerics of ancient times came to meditate and reflect on the will of \
Boccob. The valley seems to have become overgrown, but a sense of peace \
and beauty still prevaids these woods and meadows. To the south behind \
glass walls there's small room, which can be entered through a glass \
door. Around the door is some kind of shimmering field.");

    set_items(([
	"door": "The door is magnificent cut glass, beveled and arranged \
in an extremely pleasing fashion. There's a mirrored image of 'K' \
interwoven into the motif.",
	"field": "The field makes to room behind it look like it was in \
completely another world.",
      ]));

    set_virtual_exits(([
	"north":({0,-1}),
	"northeast":({1,-1}),
	"east":({1,0}),
	"southeast":({1,1}),
	"south":({0,1}),
	"southwest":({-1,1}),
	"west":({-1,0}),
	"northwest":({-1,-1}),
      ]));

    add_command("south", "south_cmd");
    //set_distant_look(1);
}

void
init_virtual() {
    call_other(PRIEST_ROOM_DIR "hallway", "tell_here",
      "You stop for a moment, it's as if you saw movement through the quartz \
beneath your feet.");
}

status south_cmd() {
    if(gates_shut) {
	this_player()->tell_me("The magic field prevents you from going \
through the door.");
	return 1;
    }
    this_player()->tell_me("You feel strange as you pass through the field. \
The feeling quickly passes.");
    return 0;
}

void
shut_gates(int shut_em) {
    gates_shut = shut_em;
}

