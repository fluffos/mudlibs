#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The shriek of a banshee breaks the eerie silence of this rocky path. A few zombies patrol this area, though most of the bodies are too far rotten to do much but twitch and groan with a souless voice. %^BLACK%^Thick black clouds %^RED%^form overhead, casting %^BLACK%^darker, longer shadows %^RED%^on this already %^BLACK%^black land%^RED%^. %^RESET%^%^MAGENTA%^Purple lightning strikes %^BOLD%^%^RED%^out from the clouds, leaving charred craters where ever they crash upon the soil.%^RESET%^");
    set_exits( ([ "east": HELLROOM+"middle_26", "west": HELLROOM+"middle_24" ]) );
}
void reset() {
    ::reset();
    if (!present("horseman", this_object()))
	new(HELLMON+"headless_horseman")->move(this_object());
    if (!present("centaur", this_object()))
	new(HELLMON+"black_centaur")->move(this_object());
    if (!present("banshee", this_object()))
	new(HELLMON+"banshee")->move(this_object());
    if (!present("raknid", this_object()))
	new(HELLMON+"she_raknid")->move(this_object());
}
