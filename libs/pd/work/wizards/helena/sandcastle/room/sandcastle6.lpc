#include <sandcastle.h>
#include <std.h>

inherit ROOM;

void create() {
::create();
set_properties((["light" : 1, "night light" : 1, "indoors" : 1]) );
set_short("Closet");
set_long("You entered the closet, and found a lot of dust. It is not very interesting in here. There is not a single grain of sand or drop of water in this room at all. All there is here is dust.");
set_items((["room" : "It is very dusty, almost like no one has been here in a very long time.", "floor" : "Dust covers your feet.", "walls" : "Scratch marks indicate an attempt to escape, but you don't see a skeleton or corpse...was this a jail of some kind?", "dust" : "If you look at it any longer it might come alive.", "sand" : "There is no sand here.", "water" : "There is no water here.", "door" : "There is not even a door here. Its just a hole in the side of the staircase. From the look of those hinges, the door seems to have been ripped off...", "hinges" : "They have been ripped off. Someone did not like this room very much."]));
set_smell("default", "The smell of dust fills your nostrils, daring a sneeze.");
set_listen("default", "There is no noise. The silence is all there is.");
set_exits( (["south" : ROOMS "sandcastle1"]) );
}
