inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Narrow alley");

    set_description(
	"A narrow alley. There is a well in the middle."
      );

    add_item("well", "You look down into the darkness. There are some \
handles on the inside."
      );

    set_exits( ([
	"north": "/room/vill_road1"
	, "east": "/room/bank"
	, "south":  "/room/post"
      ]) );

    add_command("down", "go_down");
}

int go_down() {
    this_player()->move_player("down#/room/well");
    return 1;
}
