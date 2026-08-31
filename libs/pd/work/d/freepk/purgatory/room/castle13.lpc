
#include <std.h>
#include <purgatory.h>

inherit ROOM;
void init() {
    ::init();
    add_action("move_tapestry", "move");
}
void create() {
    ::create();
     set_name("castle13");
     add_pre_exit_function("stairs","go_stairs");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^Main Subhall%^RESET%^\n"
"%^CYAN%^This is a room connecting just about every small passageway "
"%^CYAN%^in the northeast sector. Breezy and open, it houses "
"%^CYAN%^washbasins, and other things needed to use on the go. "
"%^CYAN%^Servants of the Lords and Ladies rush through here scurrying "
"%^CYAN%^to do their bidding. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
     set_listen("default", "The whistling of wind can be heard.");
 set_exits( (["northwest" : ROOMS"castle22", 
              "southwest" : ROOMS"castle8",
              "northeast" : ROOMS"castle26",
              "west" : ROOMS"castle31",
              "southeast" : ROOMS"castle18",
              "stairs" : ROOMS"guest10"]) );

    set_items( ([
        "tapestry" : "A large colorful tapestry being lightly moved by the wind, could something be behind there?"
      ]) );



}
int move_tapestry(string str) {
    if(!str) {
        notify_fail("Move what?\n");
        return 0;

    }
    if(str != "tapestry") {
        notify_fail("You can't move that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" shifts the tapestry to the side ", this_object(), ({ this_player() }));
    message("info", "You find a hole in the wall.", this_player());
    message("info", "The tapestry moved aside.", this_player());
    add_exit(ROOMS"castle36", "hole");
    call_out("go_hole", 15);
    return 1;
}

void go_hole() {
    message("info", "The tapestry flips back down.",
all_inventory(this_object()));
    remove_exit("hole");
}

void reset() {
    ::reset();
     if (children(MOBS"servant")==({})||
         sizeof(children(MOBS"servant"))<5)
            new(MOBS"servant")->move(this_object());
        
}
int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }

