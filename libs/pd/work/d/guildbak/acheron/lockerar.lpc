#include <std.h>
inherit LOCKER;

void create() {
    set_path("/adm/save/votes/acheronstorage");
    ::create();
    set_properties(([ "light":1, "night light":1, "no steal":1, "no bump":1,
"no castle":1, "no attack":1, "no teleport":1 ]));
    set("short", "Acheron Storage Room");
    set("long","%^BOLD%^%^BLUE%^At the far end of the room there are %^BOLD%^%^BLACK%^va%^BOLD%^%^WHITE%^ul%^RESET%^%^WHITE%^t-%^BOLD%^%^WHITE%^li%^BOLD%^%^BLACK%^ke %^BOLD%^%^WHITE%^lo%^RESET%^%^WHITE%^ck%^BOLD%^%^WHITE%^er%^BOLD%^%^BLACK%^s%^BOLD%^%^BLUE%^, each  "
"%^BOLD%^%^BLUE%^with a members name on them.  There seems to be two hidden "
"%^BOLD%^%^BLUE%^guards in each of the far corners of the room, to protect the "
"%^BOLD%^%^BLUE%^prize possessions of the Acheron members.");
    set_items( ([ "lockers" : "Large lockers made by a master smith for Acheron. They look to be pretty safe.",
                  "guards" : "These guards are two of the biggest, ugliest people in the realm. The only thing they know how to do is guard this room."]) );
    set_exits(([
      "north" : "/d/guilds/acheron/hall",
      "south" : "/d/guilds/acheron/mainportal",
    ]));
}
