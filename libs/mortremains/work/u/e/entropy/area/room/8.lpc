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
        "south":CRM+"2",
        "east":CRM+"9",
    ]) );
}
