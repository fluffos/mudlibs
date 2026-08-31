//Dragon quest area
//Nightshade

#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Stone Temple");
    set_properties( (["light" : 2, "night light" : 2]) );
    set_property("indoors", 1);
    set_property("no gate", 1);
    set_listen("default", "The crackling of the fire fills the room.");
    set_long("This small room contains nothing except for a large statue of a dragon and a brazier.  It's mouth is open and it's hands are back, as if it were pushing away from the wall.  The statue seems angry.  The floor here is uneven and some of the water from the well fills the depressions.  There is a large brazier in the center of the room, lighting it fully.");
    set_exits( (["west" : "/d/tirun/monastery"]) );
    add_pre_exit_function("west", "go_east");
    set_items( ([ ({"statue","dragon"}) : "The dragon stares forward menacingly.  It's a bit of a scary sight at first, but thankfully it's just a stone statue.  It's mouth is wide open."
                 ,"brazier" : "%^ORANGE%^The flame is so bright you cannot see what fuels it."
                 ,({"water","depressions"}) : "The water pools on the floor here, as if someone carried it in from the well."
                 ]) );
}

void init() {
    ::init();
    add_action("douse", "douse");
    add_action("mouth_look", "look");
}

int douse(string str) {
    if(str != "flame" && str != "fire" && str != "brazier")
        return 0;
    write("You manage to pick up some water off the floor and put out the flame.");
    call_out("finish_quest",2,this_player());
    return 1;
}

void finish_quest(object tp) {
    write("The statue begins to move away from the wall, revealing a passage!");
    write("You enter, not sure what to expect....");
    tp->move_player("/d/quests/dragon/four", "into the wall");
}

int mouth_look(string str) {
    if(str != "mouth")
        return 0;
    write("%^YELLOW%^As your face gets close to the mouth, %^BOLD%^%^RED%^FLAMES %^YELLOW%^leap out and consume you!");
    this_player()->set_paralyzed(1);
    call_out("do_move", 1, this_player());
    return 1;
}

int go_east() {
    write("%^BOLD%^%^RED%^THE FLOOR CUMBLES BENEATH YOU!!!%^RESET%^");
    return 1;
}

void do_move(object tp) {
    tp->move_player("/d/tirun/monastery", "into a conflageration");
}
