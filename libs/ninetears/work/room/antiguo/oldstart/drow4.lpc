#include "path.h"
inherit "/std/room";

void setup()
{
        set_short("Bedroom.");

        set_long("This was the family bedroom there is a very large bed to "
                "accomodate you in at one end and a largish wardrobe opposite "
                "it. The only other furniture in this room is a smallish dresser "
                "which was privately for use by your parents when you were younger. "
                "There is a your fathers sword..it used to be enchanted, but it's mystical "
                "glow seems to have gone over the time.\n");

        add_property("no_undead",1); set_light(20); 

        add_item("bed", "This is a large bed which you used to sleep in with the "
                "whole of your family. The old sheets have crumpled into dust.\n");

        add_item("wardrobe", "This is a standard hand carved wardrobe of some value, "
                "since it was carved by Bocan, a name you remember for making "
                "fantasicly constructed furniture.\n");

        add_item("dresser", "This is a small dresser by drow standards. It has "
                "various drawers and cupboards, of which many seem to be still "
                "locked.\n");

        add_item("sword", "This was your fathers old long sword. The blade is " 
                "well rusted but still seems fairly sharp.\n");
                
       add_exit("down", PATH+"drow", "door");
}
