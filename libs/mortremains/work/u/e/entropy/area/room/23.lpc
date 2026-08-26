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
        "west":CRM+"22",
    ]) );
}

void init() {
    write("You are suddenly struck by a bolt of lightning.\n");
    say(TP->QCN+" is struck by a bolt of lightning.\n");
    TP->add("hit_points",-(random(20)));
}
