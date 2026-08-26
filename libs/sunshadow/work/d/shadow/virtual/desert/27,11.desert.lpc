#include <std.h>

inherit ROOM;

int is_virtual(){ return 1; }

void create(){
    ::create();
    set_terrain(DESERT);
    set_travel(FOOT_PATH);
    set_indoors(0);
    set_light(3);
    set_name("A vast desert");
    set_short("%^ORANGE%^You are in a vast desert.%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^You are in a vast desert.\n%^RESET%^Miles of sand stretches out to in every direction except for the one north, where an overgrown Senzokuan styled elven wall rises from the sand with vines and plant life growing all along of it and down into the sand, where it looks like it might one day even come to cover all of the dunes. The sun beats down on your head.");
    set_exits(([
        "east":"/d/shadow/virtual/desert/27,12.desert",
        "west":"/d/shadow/virtual/desert/27,10.desert",
        "south":"/d/shadow/virtual/desert/28,11.desert"
        ]));
    set_smell("default","%^RESET%^%^CRST%^%^C136%^The dry desert air mixes with a faint floral scent in your nostrils.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C034%^You can hear the leaves blowing in the wind, it is so quiet here.%^CRST%^");
    set_items(([
        ]));
}

query_weather(){ return "%^BOLD%^%^WHITE%^It is oppressively hot and dry.%^RESET%^"; }