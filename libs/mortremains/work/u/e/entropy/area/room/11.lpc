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
        "south":CRM+"9",
    ]) );
}

void init() {
    write("Upon entering, you are blinded by a bright flash of light.\n");
    write("When your sight returns, you see:\n");
    TP->move_player(CRM+(random(30)+2),TP->QCN+" disappears.");
}
