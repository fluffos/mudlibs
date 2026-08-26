#include <std.h>

inherit ROOM;

int is_virtual(){ return 1; }

void create(){
    ::create();
    set_terrain(DESERT);
    set_travel(FOOT_PATH);
    set_indoors(0);
    set_light(3);
    set_name("A drying grassland");
    set_short("%^ORANGE%^You are in the drying grassland%^RESET%^");
    set_long("%^RESET%^%^ORANGE%^You are in the drying grassland\n%^RESET%^A heavily overgrown Senzokuan styled elven wall covers up the east and its growth reaches over and down into the grass with delicate flowers and the further it goes from the wall, the more the grassland is desperate in trying to survive.");
    set_exits(([
        "west":"/d/shadow/virtual/desert/26,7.desert",
        "north":"/d/shadow/virtual/desert/25,8.desert",
        "south":"/d/shadow/virtual/desert/27,8.desert"
        ]));
    set_smell("default","%^RESET%^%^CRST%^%^C136%^The dry desert air mixes with a faint floral scent in your nostrils.%^CRST%^");
    set_listen("default","%^RESET%^%^CRST%^%^C034%^You can hear the leaves blowing in the wind, it is so quiet here.%^CRST%^");
    set_items(([
        ]));
}

query_weather(){ return "%^BOLD%^%^WHITE%^It is oppressively hot and dry.%^RESET%^"; }