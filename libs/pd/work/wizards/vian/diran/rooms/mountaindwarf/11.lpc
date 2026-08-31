#include <std.h>
#include <diran.h>

inherit ROOM;
int searched;

void create() {
    ::create();
    set_properties( (["light" : 2, "night light" : 1, ]) );
    set_short( "the Mountain Dwarf city" );
    set_long("A road of carefully set stones leads out of the tundra, and is kept fairly clean of snow.  It seems to be heading toward a huge gate.  There is a small circular path surrounding a huge stone.  There is a dark hole in the stone.");
set_exits(([
"west" : ROOMS"mountaindwarf/10",
"north" : ROOMS"mountaindwarf/6",

]));
    set_items( ([
({"gate","wall"}):"The gate has been built very tall, as if to keep out unwelcome intruders.",
"road":"The road is made from various red bricks.",
"stone":"There is a large stone seemingly in the middle of this path, too large for anyone to move it.",
"hole":"You could search in it.."
]) );
    set_smell("default",  "The dry arctic wind carries little scent, although smoke can be vaguely smelled.");
    set_listen("default", "The sound of working humanoids can be heard.");
        searched = 0;

if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("mdscout"))
          new(MOB "mdscout")->move(this_object());
        if(!present("mdguard"))
          new(MOB "mdguard")->move(this_object());
          new(MOB "mdguard")->move(this_object());
}
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
    if(str != "hole")
        return 0;
    if(searched) {
        write("The hole seems to be empty.");
        return 1;
    }
    write("You find a small pile of gold!");
    say(this_player()->query_cap_name()+" finds a small pile of gold!");
        this_player()->add_money("gold", 500);
    searched = 1;
    return 1;
}