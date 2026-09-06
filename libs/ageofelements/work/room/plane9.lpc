inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("A large open plain");

    set_description(
	"A large open plain. There is a river to the east and a building to \
the west."
      );

    add_exit("west", "/room/ruin");

    add_transient_object("/obj/stethoscope");
    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "frog" })
	, ({ "set_short", "A cute little frog" })
	, ({ "set_wc", 4 })
	, ({ "set_level", 1 })
	, ({ "set_frog", 1 })
	, ({ "add_transient_object", ({ "/obj/treasure"
		, ({ "set_id", "crown" })
		, ({ "set_name", "iron crown" })
		, ({ "set_value", 30 })
		, ({ "set_short", "An iron crown" })
	      }) })
      }) );
}
