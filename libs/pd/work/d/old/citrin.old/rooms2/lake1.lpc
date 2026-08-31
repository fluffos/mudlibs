// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void init() {
::init();
add_action("beach", "beach");
}

void create() {
::create();
set_name("in the lake");
set_long("You are protected from the cold water due to the suit that "
"you wear.  The water gives a %^BLUE%^blue %^RESET%^overcast to everything "
"under the water.  A few fishes swim by.");
set_exits(([
"beach" : ROOM2"island4",
"north" : ROOM2"lake2",
]));

}

int beach() {
this_player()->force_me("remove water suit");
if(present("water suit", this_player())->remove());
write("The suit disenigrates as soon as it hits the air.");
this_player()->move_player(ROOM2"island4");
say(this_player()->query_cap_name()+" swims back to the island.");
return 1;
}
