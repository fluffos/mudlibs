#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("move_vines", "move");
}
void create() {
    ::create();
     set_name("A little used path");
     set_short("A little used path");
     set_long("Standing among trampled flowers, small fires can be seen distantly "
"to the north. This part of the courtyard looks like a herd of stampeding horses "
"just raged through. The wall to the south stands untouched, with its vines hanging "
"loosely over the stone.");
     set_properties(([
        "light"       : 2,
        "night light" : 0,
        "no bump"     : 1,
        "outside"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"yard5", 
              "northwest" : ROOMS"yard3"]) );


    set_items( ([
        "vines"  : "The vines look like they have been moved recently.",
        ({"flowers", "flower"}) : "%^BOLD%^%^YELLOW%^co%^MAGENTA%^l%^RED%^or%^BLUE%^fu%^YELLOW%^l f%^RED%^lo%^YELLOW%^we%^BLUE%^er%^MAGENTA%^s%^RESET%^ are scattered all around the area.",
        "path" : "A slightly used path looks very shabby.",
      ]) );

}
int move_vines(string str) {
    if(!str) {
        notify_fail("Move what?\n");
        return 0;

    }
    if(str != "vines") {
        notify_fail("You can't move that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" pushes some vines out of the way. ", this_object(), ({ this_player() }));
    message("info", "You find a secret entrance to the castle.", this_player());
    add_exit(ROOMS"cyard68", "southeast");
    call_out("go_hole", 10);
    return 1;
}

void go_hole() {
    message("info", "The vines move back.",
all_inventory(this_object()));
    remove_exit("southeast");
}
