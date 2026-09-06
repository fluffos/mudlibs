inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Ruin");

    set_description(
	"A very old looking ruin. There is no roof and no door."
      );

    set_exits( ([
	"south": "/room/plane4"
	, "north": "/room/plane8"
	, "east": "/room/plane9"
	, "west": "/room/plane3"
      ]) );

    add_transient_object( ({ "/obj/monster"
	, ({ "set_name", "wolf" })
	, ({ "set_level", 3 })
	, ({ "set_short", "A wolf" })
	, ({ "set_long", "A grey wolf running around. \
It has some big dangerous teeth." })
	, ({ "set_wc", 7 })
	, ({ "set_move_at_reset", 0 })
	, ({ "set_whimpy", 0 })
      }) );
}
