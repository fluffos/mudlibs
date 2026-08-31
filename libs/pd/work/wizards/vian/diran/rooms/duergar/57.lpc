#include <std.h>
#include <diran.h>
inherit ROOM;

int searched;

void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The housing compounds of the Duergar city are quite ratty and tattered.  Unlike the other housing compounds, this one seems to be abandoned.  There is a pile of junk on the ground, it looks like many people decided to leave some of their belongings behind.");
set_exits(([
"out" : ROOMS"duergar/56",

]));
    set_items( ([
         "pile of junk" : "Maybe if you search it, you'll find something useful.",
         "pile" : "Maybe if you search it, you'll find something useful.",
         "junk" : "Maybe if you search it, you'll find something useful.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
        searched = 0;
}
void init() {
    ::init();
    add_action("search", "search");
}
void reset() {
    ::reset();
    searched = 0;
}

int search(string str) {
    if(str != "junk" && str != "pile" && str != "pile of junk")
        return 0;
    if(searched) {
        write("The junk seems to have already been searched clean.");
        return 1;
    }
    write("You find a small wooden key!");
    say(this_player()->query_cap_name()+" finds a small wooden key!");
    new(OBJ"shackkey")->move(this_player());
    searched = 1;
    return 1;
}