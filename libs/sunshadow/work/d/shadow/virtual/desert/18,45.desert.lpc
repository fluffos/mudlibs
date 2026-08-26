#include <std.h>

inherit ROOM;
int fall_in();
int is_virtual() { return 1; }

void create(){
    set_indoors(0);
    ::create();
    set_terrain(LIGHT_FOREST);
    set_travel(RUTTED_TRACK);
    set_light(2);
    set_short("%^BOLD%^%^YELLOW%^A small patch of ruins");
    set_long("%^BOLD%^You are in a vast desert.\n%^RESET%^All around you, is nothing but sand. Suddenly, out of the corner of your eye, you notice a black spot in the sand. Upon closer examination, you see it is a hole in the ground.");
    set_exits(([
        "west":"/d/shadow/virtual/desert/18,44.desert",
        "south":"/d/shadow/virtual/desert/19,45.desert",
        "east":"/d/shadow/virtual/desert/18,46.desert"
        ]));
    set_smell("default", "You smell the odors of a bustling city.");
    set_listen("default", "You hear the sounds of people moving in the city.");
    set_items(([
        ({"hole","spot","black","black spot"}) : "You see a deep dark hole in the sand. From this distance it appears to be risky to get close to.",
        ]));
    //set_search("hole", (:"fall_in":));
}

int fall_in(){
    object player = this_player();
    tell_object(player, "You get too close to the hole trying to search it. You fall into the hole, and find yourself trapped.");
    tell_room(environment(player), ""+player->query_cap_name()+" falls into a hole in the sand.", player);
    player->move("/d/shadow/virtual/level1/1,1.level1");
    return 1;
}

