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
     set_long("Standing amid large growths of %^BOLD%^%^YELLOW%^co%^MAGENTA%^l%^RED%^or%^BLUE%^fu%^YELLOW%^l f%^RED%^lo%^YELLOW%^we%^BLUE%^er%^MAGENTA%^s%^RESET%^ and "
"other various undergrowth, there is a little used path to the main part of the courtyard. "
"The path dead ends to the south in a wall covered in loosly hanging vines.");
     set_properties(([
        "light"       : 2,
        "night light" : 0,
        "no bump"     : 1,
        "outside"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["north" : ROOMS"yard4", 
              "northeast" : ROOMS"yard3"]) );


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
    add_exit(ROOMS"cyard69", "southwest");
    call_out("go_hole", 10);
    return 1;
}

void go_hole() {
    message("info", "The vines move back.",
all_inventory(this_object()));
    remove_exit("southwest");
}
