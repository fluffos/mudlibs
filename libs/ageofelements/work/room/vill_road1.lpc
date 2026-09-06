inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Village road");

    set_description(
	"A long road going east through the village. The road narrows to a "
	"track to the west. There is an alley to the north and the south."
      );

    set_exits( ([
	"west": "/room/vill_track"
	, "north": "/room/yard"
	, "south": "/room/narr_alley"
	, "east": "/room/vill_road2"
      ]) );
}
