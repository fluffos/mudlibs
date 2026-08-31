#include <std.h>
#include <purgatory.h>

inherit ROOM;
//void init() {
//    ::init();
//    add_action("push_column", "push");
//}
void create() {
    ::create();
     add_pre_exit_function("north","head_north");
     add_pre_exit_function("northeast","go_stairs");
     set_name("castle24");
     set_short("The Purgatory Castle");
     set_long("%^BOLD%^%^CYAN%^The Royal Antechamber%^RESET%^\n"
"%^RESET%^%^MAGENTA%^Standing in the Royal Antechamber, a high carved ceiling "
"%^MAGENTA%^rests on tall embossed %^BOLD%^%^BLACK%^black marble%^RESET%^%^MAGENTA%^ columns set into a "
"%^MAGENTA%^polished %^WHITE%^white%^MAGENTA%^ floor. There is no place to rest. A sense of "
"%^MAGENTA%^impending doom rolls in from the northwest to surround anyone "
"%^MAGENTA%^who enters. ");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "castle"      : 1,
        "no steal"    : 1,
]));
 set_exits( (["northeast" : ROOMS"castle30", 
              "west" : ROOMS"castle29",
              "south" : ROOMS"castle21",
              "east" : ROOMS"castle14"]) );

    set_items( ([
        "column" : "%^BOLD%^%^BLACK%^A large column made from black marble holds the ceiling up.",
        "ceiling" : "Finely crafted, and well inlaid with gold and glitter, the ceiling looks more like a work of art."]) );


}
//int push_column(string str) {
//    if(!str) {
//        notify_fail("Move what?\n");
//        return 0;
//
//    }
//    if(str != "column") {
//        notify_fail("You can't move that!\n");
//        return 0;
//    }
//    
//    message("info", (string)this_player()->query_cap_name()+" leans on a column and it moves! ", this_object(), ({ this_player() }));
//   message("info", "You find a the secret entrance to the courtyards.", this_player());
//    message("info", "The column shifts to the side revealing an exit.", this_player());
//    add_exit(ROOMS"cyard70", "north");
//    call_out("go_north", 15);
//    return 1;
//}

//void go_north() {
//    message("info", "the column shifts back into position.",
//all_inventory(this_object()));
//    remove_exit("north");
//}
//int head_north() {
// if(!this_player()->is_player()) return 0;
//  return 1; }

int go_stairs() {
  if(!this_player()->is_player()) return 0;
  return 1; }

void reset() {
 ::reset();

  if (!present("lady", this_object()))
    new(MOBS"lknuckle" )->move(this_object());

}

