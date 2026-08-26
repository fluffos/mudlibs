#include "../cave.h"

inherit ROOM;
void ArrowExit();

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
      "north":CRM+"5",
      "south":CRM+"26",
      "west":CRM+"15",
      "east":CRM+"16",
    ]) );
    set("pre_exit_func",([
      "south":"ArrowExit",
    ]) );
}

void ArrowExit() {
    if(random(2)) {
	write("As you walk out, an arrow shoots from the wall and hits you in the arm.\n");
	say(TP->QCN+" is hit by an arrow as "+SUB(TP->QG)+" leaves the room.\n");
        TP->add("hit_points",-(random(10)+10));
    }
    else {
	write("An arrow shoots from the wall, but, luckly, misses you.\n");
	say("An arrow shoots from the wall "+TP->QCN+", but misses "+OBJ(TP->QG)+".\n");
    }
}
