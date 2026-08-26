#include "../cave.h"

inherit ROOM;
int LeaveEast();

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
        "east":CRM+"14",
    ]) );
    set("pre_exit_func",([
        "east" : "LeaveEast",
    ]) );
}

int LeaveEast() {
    write("As you leave, a portal opens up beneath you, and you fall in.\n");
    say("A portal opens up beneath "+TP->QCN+".\n");
    TP->move_player(CRM+(random(30)+2),"","through the portal");
    say("The portal closes.\n");
    return 1;
}
