inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Jetty");

    set_description(
	"You are at a jetty. The waves rolls in from east. A small path leads back "
	"to the west."
      );

    set_exits( ([
	"west": "/room/vill_shore2"
	, "east": "/room/sea"
      ]) );

    add_transient_object("/obj/bag");
}
