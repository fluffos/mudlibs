//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Stone Path");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no gate", 1);
    set_listen("default", "Silence is overwhelming here.");
    set_long("The path here splits into three different hallways.  There is the head of a dragon above each one, each a different color.  Nothing can be seen down any path except complete darkness.");
    set_exits( (["northwest" : "/d/quests/dragon/white", "north" : "/d/quests/dragon/red", "northeast" : "/d/quests/dragon/black", "up" : "/d/quests/dragon/blue"]) );
    add_invis_exit("up");
    add_pre_exit_function("northwest", "go_northwest");
    add_pre_exit_function("north", "go_north");
    add_pre_exit_function("northeast", "go_northeast");
    add_pre_exit_function("up", "go_up");
    set_items( ([ ({"dragon","head","heads"}) : "%^RESET%^%^BOLD%^The dragon head above the northwest path appears to be smiling.\n%^RESET%^%^RED%^The dragon head above the north path looks down objectively.\n%^BOLD%^%^BLACK%^The dragon head above the northeast path is snarling."]) );
}

void init() {
    ::init();
    add_action("peer", "peer");
}

int peer(string str) {
    if(str != "northwest" && str != "north" && str != "northeast" && str != "up")
        return 0;
    if(str == "up") {
        write("You cannot see far in that direction.");
        return 1;
    }
    write("Darkness blocks any distant vision.");
    return 1;
}

int go_northwest() {
    write("%^RESET%^%^BOLD%^You are taken into the realm of the white dragon...");
    return 1;
}

int go_north() {
    write("%^RESET%^%^RED%^You are taken into the realm of the red dragon...");
    return 1;
}

int go_northeast() {
    write("%^RESET%^%^BOLD%^%^BLACK%^You are taken into the realm of the black dragon...");
    return 1;
}

int go_up() {
    write("%^RESET%^%^BLUE%^You are taken into the realm of the blue dragon...");
    return 1;
}
