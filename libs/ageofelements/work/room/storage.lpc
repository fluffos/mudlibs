inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("A small storage room");

    set_description(
	"You are in a small and dusty storage room. You can see the shop "
	"through the opening to the east."
      );

    add_exit("east", "room/shop");
}

void init_room() {
    object ob;
    int does_exist;

    if (!present("tech_quicktyper", this_player())
	&& !present("tech_quicktyper", this_object())
      ) {
	ob = clone_object("obj/quicktyper");
	move_object(ob, this_object());
    }
}

