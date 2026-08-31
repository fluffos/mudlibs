//Stormbringer
#include <std.h>
#include <tirun.h>
inherit ROOM;
int fruit;
void init() {
    ::init();
    add_action("do_pluck","pluck");
}
void create() {
    ::create();
    set_short("A grove of trees.");
    set_properties( (["light" : 3, "night light" : 2]) );
    set_property("forest", 1);
    set_smell("default", "It smells of a afternoon spring rain.");
set_long("A well tended grove of trees.  The area seems to radiate magic.  Some of the trees have fruit on them.  To the north, one tree towers above all the others.  A path leads off the the west.");
    set_night_long("The grove of trees is more peaceful than the rest of the forest. The darkness of night does not dimm the beauty of the grove. ");
    set_exits( (["enter" : ROOMS+"fighter/ranger/ranger_join"
             ,"west" : ROOMS+"clergy/druid/druid_grove"
              ]) );
    set_items( ([ "trees" : "Healthy trees of a drak green. Some of the trees have fruit growing on them."
                 ,"tree" : "The tree stands at least twice as tall as the other trees in the area."
                 ,"fruit" : "Eatable fruit grows on some of the trees. You might try plucking some."
                 ,"path" : "A path leading to the east."
                 ]) );
}
void reset() {
    ::reset();
      fruit = 1;
    if(!present("tent"))
new("/d/nopk/standard/obj/misc/tent")->move(this_object());
    if(!present("campfire"))
new("/d/nopk/standard/obj/misc/forage/campfire")->move(this_object());
}
int do_pluck(string str) {
    if(!str) {
        notify_fail("Pluck what?\n");
        return 0;
    }
    if(str != "fruit") {
        notify_fail("You can't pluck that!\n");
        return 0;
    }
    if(fruit==0) {
        notify_fail("All the fruit seems to be gone.\n");
        return 0;
    }
    if(fruit=1) {      
    write("You pluck a nice juicey piece of fruit.");
     say((string)this_player()->query_cap_name()+" plucks a large juicey piece of fruit from a tree.");
    new(OBJ"fruit")->move(this_object());
    fruit=0;
    return 1;
  }
}
