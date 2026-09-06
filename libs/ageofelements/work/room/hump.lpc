inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Humpbacked bridge");

    set_description(
	"An old humpbacked bridge."
      );

    set_exits( ([
	"east": "/room/vill_green",
	"west": "/room/wild1",
      ]) );

    add_transient_object( ({ "/obj/torch"
	, ({ "set_name", "stick" })
	, ({ "set_fuel", 500 })
	, ({ "set_weight", 1 })
      }) );

    add_transient_object( ({ "/obj/money"
	, ({ "set_money", 10 })
      }) , "Some coins are tossed up onto the bridge." , 100);
}
