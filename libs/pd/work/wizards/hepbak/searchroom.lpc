#include <std.h>
#include <marsh.h>
inherit ROOM;
int g;
void init() {
    ::init();
    add_action("search_gem", "search");
}
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Weapons, work tools, and junk is stored here."
         
    );
    set_items(([
        "weapons" : "Mostly sticks.",
        "work tools" : "Mostly sticks, and rocks.",
        "junk" : "Discarded gems.",
        "sticks" : "It's little branches that have fallen from "
                   "trees.  What else can a stick be.",
        "tools" : "Mostly sticks, and rocks.",
        "rocks" : "It looks a little like a pick, to pick away "
                  "at the sand to form tunnels.",
        "gems" : "They must have found them while digging.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : NEST "est63",
    ])  );
}
void reset() {
    ::reset();
      g = 1;
}
int search_gems(string str) {
    if(!str) {
        notify_fail("Search what?\n");
        return 0;
    }
    if(str != "gems") {
        notify_fail("You don't find anything.\n");
        return 0;
    }
    if(g==0) {
        notify_fail("You don't find anything.\n");
        return 0;
    }
    if(g=1) {      
    write("You find a beuatiful gem!");
    say((string)this_player()->query_cap_name()+" finds a beautiful gem!");
    new(ITEMS"gem")->move(this_object());
    g=0;
    return 1;
  }
}
