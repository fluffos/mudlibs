// Chernobog (6/23/22)
// Morpos's Lab

#include <std.h>

inherit ROOM;

void create(){   
    ::create();
    set_property("indoors",1);
    set_property("light",1);
    set_property("no sticks",1);
    set_short("Demiplane Research Laboratory");
    set_long("%^RESET%^%^CRST%^%^C025%^This room is much less cluttered than the adjacent laboratory, lacking the bookshelves and resources for study. Instead, %^C058%^worktables %^C025%^have been scattered about the room, each specified to a different task and covered in %^C245%^p%^C220%^r%^C249%^o%^C251%^j%^C226%^e%^C220%^c%^C247%^t%^C245%^s %^RESET%^%^C025%^that are in mid-process. A small pile of odd %^C244%^stones %^C025%^have been stacked in the corner, humming and %^C118%^gl%^C154%^ow%^C148%^in%^C118%^g %^RESET%^%^C025%^lightly. %^CRST%^\n");
    set_smell("default","The air is full of a strange scent.");
    set_listen("default","Tinkering sounds of someone doing delicate work fill the air.");
    set_items(([
        ({"stones", "pile"}) : "%^RESET%^%^CRST%^%^C025%^The %^C244%^stones %^C025%^are small, about the size of a human fist. Each has been marked by one of several strange %^C118%^gl%^C154%^ow%^C148%^in%^C118%^g s%^C154%^ig%^C148%^il%^C118%^s%^C025%^, vibrating faintly and offering a odd low hum.%^CRST%^",
        ({"worktable", "worktables"}) : "%^RESET%^%^CRST%^%^C025%^These %^C058%^tables %^C025%^are constructed of thick %^C130%^planks of wood %^C025%^and scaled for the smaller races. The surfaces have been %^C124%^marred %^C025%^by countless dings and scrapes while being used.%^CRST%^",
        "projects" : "%^RESET%^%^CRST%^%^C025%^One table has a complex %^C245%^c%^C220%^l%^C249%^o%^C251%^c%^C226%^k%^C220%^w%^C214%^o%^C249%^r%^C247%^k %^RESET%^%^C025%^contraption, with wings and limbs that seem insectoid. Another is covered in a collection of %^C096%^jars %^C025%^with various %^C040%^p%^C046%^i%^C226%^g%^C220%^m%^C208%^e%^C202%^n%^C196%^t%^C124%^s%^RESET%^%^C025%^, a few that even %^C045%^g%^C051%^l%^C045%^o%^C039%^w %^RESET%^%^C025%^softly in the dim light here. Some of these others are simply incomprehensible.%^CRST%^",
        ]));
    set_exits(([
        "north" : "/d/common/obj/daily/entrance",
        ]));
}

void reset(){
    ::reset();
    if(!present("morpos")) new("/d/common/obj/pets/morpos")->move(this_object());
}

