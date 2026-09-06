inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Mountain pass");

    set_description(
	"You are in a pass going into the mountain with a steep slope "
	"upwards to the north. However, the path is barred. There is a "
	"tunnel entrance to the north. It might be possible to climb "
	"up."
      );

    set_exits( ([
	"south": "/room/plane11"
	, "north": "/room/mine/tunnel"
	, "up": "/room/ravine"
      ]) );
}
