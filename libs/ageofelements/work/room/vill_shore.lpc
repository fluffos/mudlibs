inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Road");

    set_description(
	"You are on a road going out of the village. Eastroad runs north "
	"from here, along the eastern perimeter of the city, and to the "
	"south are some fields planted with all the crops that the city "
	"needs. The main road runs towards the shore to the east, and into "
	"the city to the west."
      );

    set_exits( ([
	"west": "/room/vill_road2"
	, "east": "/room/jetty"
	, "north": "/room/eastroad1"
	, "south": "/room/crop"
      ]) );
}
