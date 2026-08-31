#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "Sky Park");
    set("long","%^BOLD%^%^CYAN%^The path begins to widen as it continues towards the east. Small trees made from clouds grow along the path's edge. Around the trees, the lushious clouds shift slightly allowing a %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^ll%^CYAN%^ to be seen to the northeast. This area is calm and peacdful.%^RESET%^");
    set_items( ([ "waterfall": "%^BOLD%^%^BLUE%^A %^BLUE%^w%^CYAN%^a%^BLUE%^t%^CYAN%^e%^BLUE%^rf%^CYAN%^a%^BLUE%^ll%^CYAN%^ can slightly be seen towards the northeast.%^RESET%^", "trees": "%^BOLD%^%^WHITE%^Small trees made from clouds grow along the path's edge.%^RESET%^" ]) );
    set_exits( ([ "southwest" : SKYROOM "m1", "east" : SKYROOM "m9" ]) );
}
void reset() {
    ::reset();
    if (!present("monk", this_object()))
	new(SKYMOB "repenting_cleric")->move(this_object());
    if (!present("priest", this_object()))
	new(SKYMOB "priest")->move(this_object());
    if (!present("penguin", this_object()))
	new(SKYMOB "penguin_2")->move(this_object());
}
