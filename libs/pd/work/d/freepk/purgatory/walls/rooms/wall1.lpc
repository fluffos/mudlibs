//Wraith RAR!
#include <std.h>
#include <castlewall.h>

inherit ROOM;
void init() {
    ::init();
    add_action("open_door", "open");
}
void create() {
    ::create();
     set_name("The Castle Walls");
     set_short("The Southwest Guard Tower");
     set_day_long("%^BOLD%^%^WHITE%^The Southwest Guard Tower.%^RESET%^\n"
"Fortified %^BOLD%^%^WHITE%^stone%^RESET%^ walls rise up above the walkway "
"to provide cover for the guards as they walk their rounds. A well worn path "
"has been etched into the hard walkway from the years of patrols that have "
"moved around these walls. A large heavy steel braced door has been closed to "
"the north, the path continues to the east and west.");
     set_night_long("%^BOLD%^%^WHITE%^The Southwest Guard Tower.%^RESET%^\n"
"%^BOLD%^%^BLACK%^The %^BOLD%^%^YELLOW%^l%^WHITE%^i%^YELLOW%^g%^WHITE%^h%^YELLOW%^t%^WHITE%^s%^BLACK%^ of the city can been seen far below and faintly in "
"%^BOLD%^%^BLACK%^the distance as night makes its presence known. Weary guards "
"%^BOLD%^%^BLACK%^switch shifts as rested ones come to replace them. The quiet "
"%^BOLD%^%^BLACK%^of the night allows sounds to drift in from the rooms around, "
"%^BOLD%^%^BLACK%^snippets of conversation can be heard from the north and the grumbling of "
"%^BOLD%^%^BLACK%^disgruntled guards can be heard from the east and west.");
     set_properties(([
        "light"       : 2,
        "night light" : 1,
        "no bump"     : 1,
        "outside"     : 1,
        "no steal"    : 1,
]));
 set_exits( (["east" : ROOMS"castle2", 
              "west" : ROOMS"wall8",
]) );

    set_items( ([
        "stone" : "Worn stone has been set into the walls.",
        "walkway" : "A heavily used walkway that has seen many years and generations of feet.",
        "door" : "A heavy, thick door that has wide iron straps on it hangs open to let the cool breeze in to the room.",
        "lights" : "Hazy and flickering lights dot the city-scape as people prepare for the night.",
        "city" : "The city prepares itself for the coming night, street lamps are turned on and families gather their children.",
        "night" : "The darkness of night befalls the city with the setting of the sun. Animals and people alike turn in for a good nights sleep.",
      ]) );
set_listen("default","The talk of the guards hangs in the air.");
set_smell("default","Weapon oil, leather, and the scents of the city waft in on the breeze.");

}
int open_door(string str) {
    if(!str) {
        notify_fail("open what?\n");
        return 0;

    }
    if(str != "door") {
        notify_fail("You can't open that!\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" opens a door.", this_object(), ({ this_player() }));
    message("info", "You open a door.", this_player());
    add_exit(ROOMS"wall9", "enter");
    call_out("go_hole", 60);
    return 1;
}

void go_hole() {
    message("info", "High winds slam a door nearby.",
all_inventory(this_object()));
    remove_exit("enter");
}
void reset() {
 ::reset();
  if (!present("archer", this_object()))
    new(MOBS"darkarcher" )->move(this_object());
  if (!present("archer 2", this_object()))
    new(MOBS"darkarcher" )->move(this_object());
  if (!present("watchman", this_object()))
    new(MOBS"watchman" )->move(this_object());


}
