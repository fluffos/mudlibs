
#include "../seaworld.h" 

void reset(int arg) 
{
    ::reset(arg);

    if (filter_live(this_object()) < 2)
    {
	CM("shark1");
	CM("shark2");
	CM("shark3");
	CM("shark4");
    }
    if (arg) return; 
    set_light(1);
    short_desc = "In the sea";
    long_desc = BS(
      "As you enter this black caverne you get a strange feeling. "
      + "There is normally a big white shark waiting for humans to enter "
      + "There are black stones all around you. The water is horrible "
      + "cold and dark. Maybe there is a possibility to dive down.");
    items= ({ "water","Dark sea water",
      "stones","Huge black stones",
      "bottom","A sandy sea bottom" });
    dest_dir = 
    ({
      PATH+"sw23", "west"
    });
}

init() {
    ::init();
    add_action("dive","dive");
}

int dive() 
{
    this_player()->move_player("down#players/whisky/seaworld/room/cavern");
    return 1;
}

