inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Lair of the Giant");

    set_description(
	"There are mountains all around you."
      );

    set_exits( ([
	"east": "/room/giant_path"
	, "west": "/room/giant_conf"
      ]) );

    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "giant" })
	, ({ "set_level", 15 })
	, ({ "set_short", "A giant" })
	, ({ "set_wc", 20 })
	, ({ "set_ac", 2 })
	, ({ "set_aggressive", 1 })
      }) );
}
