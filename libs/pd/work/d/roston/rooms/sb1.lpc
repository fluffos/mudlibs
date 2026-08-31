#include <std.h>
#include <roston.h>
inherit ROOM;
void create() {
    ::create();
    set_name("Bards House");
    set_properties((["light":2,"nightlight":3]));
    set_short("secret building");   
    set_long("%^RESET%^%^ORANGE%^The room is small and offers very little light. Picture frames line the walls allowing visiters to see the Old Bard's family. On the ground are dark faded rugs that offer no warmth. The piano in the corner of the room is the only thing that looks new and not worn.%^RESET%^");
    set_items((["frames" : "There are 5 poorly crafted picture frames that show an array of family photos.", "rugs"   : "Old and tattered, these rugs bring no warmth to the room.", "piano"  : "The piano is the only thing in the room that looks like it gets attention."])); 
    set_exits((["west" : ROOMS "sb3", "north" : ROOMS "sb2", "out" : ROOMS "roston23"]));
}                                                     
void reset() {
    ::reset();
    if(!present("gypsy child")) 
	new(MOB"gypsy_child")->move(this_object());
    if(!present("bard child")) 
	new(MOB"bard_child")->move(this_object());
}  
