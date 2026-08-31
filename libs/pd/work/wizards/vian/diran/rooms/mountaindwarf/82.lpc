#include <std.h>
#include <diran.h>
inherit ROOM;
void init() {
    ::init();
    add_action("go_east", "east");
}

void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]));
    set_short("a large tent.");
    set_long("This large tent is fitted with tables that hold the merchandise of the store.  An old mountain dwarf, Ria, tends to the store, which sells armour, weapons, and items.");
    set_exits(([
"out" : ROOMS"mountaindwarf/79",
      ]));
          set_items( ([
({"tables"}):"The tables, made from white wood, are very sturdy looking.",
"merchandise":"The tables are filled with armour, weapons, and general items.",
]) );
}

void reset() {
    ::reset();
    if(!present("ria")) 
        new(MOB"ria")->move(this_object());
}

int go_east() {
    if(!wizardp(this_player())) {
        message("my_action", "The storeroom isn't meant for players to visit.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " begins to leave east then thinks better of it.",
          this_object(), ({ this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS "storage", "east");
    return 1;
}


