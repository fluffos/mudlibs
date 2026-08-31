// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;
int rt;

void init() {
::init();
add_action("search", "search");
}

void create() {
::create();
set_name("small island");
set_long("The sand here is splattered red here from a recent battle.  "
"Animal parts lay around the area.  Some boar tusks lay buried in the "
"sand.  Several small wings lay here from pixies.");
set_smell("default", "The smell of blood is here.");
set_exits(([ 
"south" : ROOM2"island2",
]));
}

void reset() {
::reset();
rt = 1;
if (!present("sand pixie"))
new(MON2"pixie2")->move(this_object());
}

int search(string str) {
    if(!str) {
        notify_fail("Search what?\n");
        return 0;
    }
    if(str != "sand") {
        notify_fail("You don't find anything.\n");
        return 0;
    }
    if(rt==0) {
        notify_fail("You don't find anything.\n");
        return 0;
    }
    if(rt=1) {      
    write("You find a pair of boar tusks.");
    new("/d/citrin/objects2/tusks")->move(this_object());
    rt=0;
    return 1;
  }
}
