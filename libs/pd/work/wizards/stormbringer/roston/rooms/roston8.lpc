#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
  ::create();    
set_name("Armour Shop");
set_items((["snow"   : "A very deep white snow",
            "dirt"  : "A light brown mixture"]));        
set_properties((["light":2, "night light":3]));
set_short("Roston Armour Shop");
set_long("The roston Armour Shop.\nThis is where all the "
         "Dwarven hunters come to sell and buy armour. Joey the "
         "shop keeper approaches and tries to sell some of his wares.");

set_exits( ([ "east" : ROOMS "roston7" ]));
}

void init() {
    ::init();
    add_action("go_west", "west");
}

void reset() {
    ::reset();
    if(!present("joey")) 
        new(MOB"joey")->move(this_object());
}

int go_west() {
    if(!wizardp(this_player())) {
        message("my_action", "Joey stops you from entering his storage area.",
          this_player());
        message("other_action", (string)this_player()->query_cap_name()+
          " is held back from going west.",
          this_object(), ({ this_player() }));
        return 1; 
    }
    this_player()->move_player(ROOMS"rostonstorage", "west");
    return 1;
}
