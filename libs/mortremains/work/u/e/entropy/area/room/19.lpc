#include "../cave.h"

inherit ROOM;
void Fence();
void Sleep();
void Scare();
void WizardFun();

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
        "west":CRM+"18",
        "south":CRM+"25",
    ]) );
}

void init() {
    if(!random(10)) call_out(3,"WizardFun");
}

void WizardFun() {
    switch(random(3)) {
        case 0: Fence();
        case 1: Sleep();
        default: Scare();
    }
}

void Sleep() {
    write("A wizard appears in a puff of smoke. He grins and mumbles something incoherent\n");
    write("as he waves his wand at you. You suddenly feel sleepy.\n");
    new(COBJ+"sleep-obj")->move(TP);
    say("A wizard appears before "+TP->QCN+", waves his wand and disappears.\n");
}

void Fence() {
    write("A strange old man appears before, dressed in what appears to be something a normal\n");
    write("wizard would wear. He looks you over and says 'Fence', before disappearing.\n");
    new(COBJ+"fence-obj")->move(TP);
    say("A wizard appears before "+TP->QCN+", waves a wand at "+OBJ(TP->QG)+", and disappears.\n");
}

void Scare() {
    write("A wizard appears before you. He looks at you angrily, shakes a wand at you, and\n");
    write("grins. 'Fear!' he yells before disappearing in a cloud of smoke.\n");
    say("A wizard appears, shakes a wand at "+TP->QCN+", yells 'Fear!' and disappears.\n");
    new(COBJ+"fear-obj")->move(TP);
}
