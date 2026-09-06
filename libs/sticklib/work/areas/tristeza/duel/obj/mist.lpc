
/*
** The mist in forest.
**
** Code by Tron.
**
***********************/

#include <areas.h>

#define CLEAR_TIME 60
#define	MIST_MOVE	AREA_TRISTEZA "duel/obj/mist_move"

object room;
string rand_dir;
status executing;

void init();

string
short() {
    return "Thick mist";
}

string
query_long() {
    return "You are in the middle of thick mist.\n"+
    "You can hardly see your own legs.\n"+
    "Right now you can't see where you are heading.";
}

void
clear() {
    object ob;

    ob=present("mist_move", room);
    if(ob) destruct(ob);

    tell_room(room, "A sudden blow of wind clears the mist...\n");

    destruct(this_object());
}

void
do_shadow(object ob) {
    room=ob;
    if(ob->query_prevent_shadow()) { clear();return; }
    call_out("clear", random(CLEAR_TIME));

    shadow(room);
    init();
}

status
query_mist() { return 1; }

void
init() {
    object ob;

    room->init();
    if(!(ob=present("mist_move", room))) {
	ob=clone_object(MIST_MOVE);
	move_object(ob, room);
    }
    else ob->init();
}

void
myinit() { room->init(); }
