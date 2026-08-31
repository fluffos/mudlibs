#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1]));
    set_short("Uale Road");
    set_smell("default", "Seaweed smells drift past here, faint but noticeable.");
    set_listen("default", "The mumble of hard working citizens is heard.");
    set_long("Uale Road runs south and then southeast to the %^BOLD%^%^GREEN%^Seaweed farms%^RESET%^, one of the pride and joys of the NuShae Kingdom. To the east the path continues towards the palace walls. To the north a store and Tereva Court are visible. Off the road to the west is the back of another store.");
    set_night_long("Uale Road runs south and then southeast to the %^BOLD%^%^GREEN%^Seaweed farms%^RESET%^, one of the pride and joys of the NuShae Kingdom. To the east the path continues towards the looming palace walls. To the north the outline of a door and the cobbles of Tereva Court are barely visible.");
    set_items((["palace" : "The Palace stands tall, with four visible towers rising towards the surface of the ocean. The doors leading inside are open and inviting.", "door" : "It is the entrance to a shop.", "path" : "This is the path to the %^BOLD%^%^GREEN%^Seaweed farms%^RESET%^."]));
    set_exits( (["north" : ROOMS"t3", "east" : ROOMS"seaweed2"]) );
}
