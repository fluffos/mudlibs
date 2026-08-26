#include "../cave.h"

inherit ROOM;
void MovePlayer();
void MovePlayer2();

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
        "west":CRM+"5",
    ]) );
}

void init() {
    call_out(1,"MovePlayer");
}

void MovePlayer() {
    write("Suddenly, a large demon appears before you.\n");
    say("A large demon appears, waves his wand at "+TP->QCN+" and disappears.\n");
    say(TP->QCN+" faints.\n");
    write("He mumbles something under his breath and waves his wand at you.\n");
    write("You faint.\n");
    call_out(1,"MovePlayer2");
}

void MovePlayer2() {
    write("You open your eyes to see:\n");
    TP->move_player(CRM+(random(20)+2),TP->QCN+" suddenly disappears.\n");
}
