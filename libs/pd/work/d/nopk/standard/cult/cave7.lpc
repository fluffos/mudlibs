#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 1, "indoors" : 1]));
    set("short", "A dark chamber");
    set("long",
	"The bottom of the dark cave has magnificent rock formations along the "
	"walls, ceiling, and ground. Giant pillars of rock reach from the rock "
	"ceiling to the ground. Water drips from unseen cracks above. Fungi and "
	"moss grow in patches on the walls. An iron trap door leads back out of "
	"this room, going up."
    );
    set_items(([
    ]));
    set_exits(([
	"up" : ROOMS"cult/cave6"
    ]));
}
