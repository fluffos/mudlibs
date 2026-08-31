#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "HAMEN'S TOMB");
    set("long", "%^BOLD%^%^WHITE%^Inside the palace walls, there are egyptian structures everywhere. There is a large picture of King Hamen placed above the head of the stone stairs. There doesn't seem to be many people around the base of the castle. Which is odd, as this room is so close to King Hamen.\n");
    set_items( ([ "picture": "%^BOLD%^%^WHITE%^This picture is of the King of the tomb, King Hamen." ]) );
    set_exits( ([ "west" : ROOMS+"center_1", "south" : ROOMS+"hamen_tomb_30", "north" : ROOMS+"hamen_tomb_34"]) );
}
