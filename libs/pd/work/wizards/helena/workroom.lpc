#include <std.h>

inherit ROOM;

void create() {
  ::create();
    set_properties( ([ "light" : 3, "night light" : 2, "indoors" : 1, "no attack" : 1, "no scry" : 1, "no steal" : 1]) );
    set_short("Helena's Hideout");
    set_long("You have entered Helena's room. Being the simple person she is, there is a desk, a very comfy looking chair, and a painting above the desk. You notice on the desk a scroll of parchment, a framed photo of Tsuke, and one solitary pen. There are two torches nicely placed to light up the room in the event of it being night. There appears to be no bed. Perhaps she sleeps somewhere else?");
    set_night_long("It is now night, but the room is still well lit due to the two torches which have been set aflame mysteriously. Everything is as it was during the day, with the desk, the chair, and the painting, except all is now lit by the glow of the torches.");
    set_items((["room" : "It's very bare...but somehow still messy...", 
                "desk" : "It has a scroll, a pen, and a photo of Tsuke on it.", 
                "chair" : "It's one of those leather chairs...but you decide against sitting in it...you might fall asleep.", 
                "painting" : "The signature says Van Gough...", 
                "scroll" : "You can't read whatever's written on it, but there is some wierd doodle of a flying turtle...", 
                "photo" : "It's a photo of Tsuke...god he's handsome!", 
                "pen" : "It looks about two hundred years old...apparently it still works.", 
                "torch" : "A torch which burns when the sun sets, and extinguishes when the sun rises again.", 
                "floor" : "Nice, comfy, and warm...but made of concrete.", 
                "wall" : "There are no windows...this is a very bare room."]));
    set_smell("default", "There is no source of smell, but there's a tinge of lavender in the air.");
    set_listen("default", "Your feet don't seem to make a sound as you walk the floor, and a faint violin can be heard playing soothin notes.");
    set_exits( (["sleep" : "/d/guilds/illuminati/rooms/tsuke", "square" : "/d/nopk/tirun/square", "sage" : "/d/nopk/tirun/sage_room", "hall" : "/d/nopk/standard/adv_inner"]) );
    add_invis_exit("hall");
}
