// Basic room school by Avelan
// room #4, the example
// May 2001

#include "defs.h";
inherit OUTSIDE_OBJ;

void setup(){

    set_light(80);
    set_short("day and night room");
    set_determinate("the ");

    set_day_long("This place will demonstrate how the time of"
      " the day can be used to affect how the room looks.  There"
      " are a few birds flying around happily and a mysterios looking"
      " womble is wombling in one corner.  A huge pile of idleness"
      " lies in the middle of the room, probably left there by"
      " Shaydz.\n");

    set_night_long("This place will demonstrate how the time of"
      " the day can be used to affect how the room looks.  The"
      " place is quite empty at this time of the day, however "
      " there is a womble sleeping in one corner and a huge pile of"
      " something disgusting is sitting in the middle of the room.\n");


    add_item("place","This place smells funny, like something"
      " idled here for a long time.");
    add_item("room","A nice little room with a feeling of"
      " comfort in it.");
    add_item(({"pile","pile of idleness","idleness"}),
      "The pile is simply a disgusting pile of idleness"
      " which can only be created by the very best idlers"
      " around, the admin.");

    add_day_item("bird","The birds are flying around happily"
      " making the place perfect for idling.");
    add_day_item("womble","The womble looks at you with his"
      " puppy dog eyes, he is totally adorable.");
    add_day_item("shaydz","Before you stands a mighty looking"
      " meanie with a wand of 'make idle' in one hand and a"
      " potion of 'reboot mud' in the other.");
    add_day_item("corner","The womble stands there.");
    add_day_item("wand","The wand makes anyone it's used"
      " on idle for atleast 1 hour.");
    add_day_item("potion","The potion, if used properly,"
      " will reboot the mud, luckily Shaydz never did"
      " learn how to use it.");

    add_night_item("womble","The womble is sleeping in the"
      " corner, looking very silent.");
    add_night_item("corner","The corner is conquered by the"
      " womble sleeping there.");

    room_day_chat(({ 120, 240, ({
          "Shaydz zaps you with his wand of make idle.",
          "A horrid laughter eminates from the pile of idleness.",
          "The womble wombles around happily.",
          "The womble almost makes you want to womble.",
          "Shaydz gets a very EVIL look on his face.",
          "Shaydz takes a sip of the potion of reboot mud."
        }) }) );

    room_night_chat(({ 120, 240, ({
          "The womble starts to womble in his sleep.",
          "The pile looks like it's alive.",
          "The womble opens his eyes just for a second.",
          "The womble shakes, it must be seeing nightmares."
        }) }) );

    add_exit("back",ROOMSC "room_school04","path");


}
