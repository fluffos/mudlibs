inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("Village road");

    set_description(
	"A long road going through the village. There are stairs going down. "
	"The road continues to the west. To the north is the shop, and to the "
        "south is the adventurer's guild. The road runs towards the shore to "
        "the east."
      );

    set_exits( ([
	"west": "/room/vill_road1"
	, "east": "/room/vill_shore"
	, "south": "/room/adv_guild"
	, "down": "/room/station"
	, "north": "/room/shop"
      ]) );

    add_transient_object("/room/npc/harry", "Harry arrives.");
}
