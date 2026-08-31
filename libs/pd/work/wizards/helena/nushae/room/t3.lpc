#include <std.h>
#include <nushae.h>

inherit ROOM;

void create() {
  ::create();
    set_properties((["light" : 2, "night light" : 2, "beach" : 1]) );
    set_short("East Tereva Court");
    set_listen("default", "The swill of the oceans and the soft mumble of voices sound here.");
    set_smell("default", "The smells of fresh food and clean surfaces float past.");
    set_long("Tereva Court leads directly to the Palace of the King of %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^. Taking up the view to the east is the Palace gates, intimidating and yet inviting at the same time, intriguing to any traveler, as the King's Palace is open to all. The lights to the west show you the public square, while a doorway stands to the north, with a sign out front. To the south is the path to the %^BOLD%^%^GREEN%^Seaweed farms%^RESET%^.");
    set_night_long("Tereva Court leads directly to the Palace of the King of %^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^. Taking up the view to the east is the Palace gates, intimidating and yet inviting at the same time, intriguing to any traveler, as the King's Palace is open to all. Bright lights pierce the night to mark the public square. The outline of a door and a sign can be seen to the north. A path can be just made out to the south.");
    set_items((["palace" : "The Palace stands tall, with four visible towers rising towards the surface of the ocean. The doors leading inside are open and inviting.", "lights" : "The bright lights mark the presence of the NuShae Public Square.", "sign" : "There is something on the sign. Perhaps it is readable?", "door" : "It is the entrance to a shop.", "path" : "This path leads to the %^BOLD%^%^GREEN%^Seaweed farms%^RESET%^."]));
    set_exits( (["west" : ROOMS "t1", "north" : ROOMS "gstore", "east" : ROOMS"pentrance", "south" : ROOMS"seaweed1"]) );
}

void init() {
::init();
add_action("read", "read");
}
int read(string str) {
if(!str)
if(str != "sign") return 0;
write("%^CYAN%^Nu%^MAGENTA%^Sh%^CYAN%^ae%^RESET%^ %^ORANGE%^General Store%^RESET%^. All are welcome to come trade inside.");
return 1;
}

void reset() {
    ::reset();
     if (children(MOB"fish")==({})||
         sizeof(children(MOB"fish"))==1)
            new(MOB "fish")->move(this_object());
}
