#include "../cave.h"

inherit ROOM;

void create() {
    ::create();
    seteuid(getuid());
    set("light",1);
    set("short","an indescript room");
    set("long",@EndText
An indescript room, just waiting to be filled with many nouns, adjectives, and verbs.
EndText
    );
    set("items",([
    ]) );
    set("exits",([
        "west":CRM+"16",
        "south":CRM+"22",
    ]) );
    set("pre_exit_func",([
        "south":"LeaveSouth",
    ]) );
}

int LeaveSouth() {
    if(random(5)) {
        write("Before you can leave, a large whirlwind enters the room and engulfs you.\n");
        TP->move_player(CRM+(random(10)+2),TP->QCN+" is engulfed by a whirlwind.");
        return 1;
    }
    else return 0;
}
