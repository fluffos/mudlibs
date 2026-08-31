#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "EYE OF HELL");
    set("long","%^BOLD%^%^RED%^The shriek of a banshee breaks the eerie silence of this rocky path. A few zombies patrol this area, though most of the bodies are too far rotten to do much but twitch and groan with a souless voice. %^BLACK%^Thick black clouds %^RED%^form overhead, casting %^BLACK%^darker, longer shadows %^RED%^on this already %^BLACK%^black land%^RED%^. %^RESET%^%^MAGENTA%^Purple lightning strikes %^BOLD%^%^RED%^out from the clouds, leaving charred craters where ever they crash upon the soil.%^RESET%^");
    set_exits( ([ "north": HELLROOM+"middle_6", "southeast": HELLROOM+"middle_4" ]) );
}
void reset() {
    ::reset();
    if (!present("wizard", this_object()))
	new(HELLMON+"powerful_wizard")->move(this_object());
    if (!present("knight", this_object()))
	new(HELLMON+"sauran_knight")->move(this_object());
}
