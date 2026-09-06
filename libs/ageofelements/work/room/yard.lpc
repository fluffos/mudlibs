inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Small yard");

    set_description(
	 "A small yard surrounded by houses and a pub to the east."
      );

    set_exits( ([ "south": "/room/vill_road1"
	,  "east": "/room/pub2"
      ]) );

    add_transient_object("/room/npc/beggar", "Beggar arrives.");

    add_transient_object( ({ "/obj/weapon"
	, ({ "set_name", "knife" })
	, ({ "set_class", 5 })
	, ({ "set_value", 8 })
	, ({ "set_weight", 2 })
      }) );
}
