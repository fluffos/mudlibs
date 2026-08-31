#include <petzoo.h>
#include <std.h>
inherit "std/room";

void create() {
    ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    set("short", "The Aquarium");
    set("long", "You are near one of the outer walls of the aquarium.  There is a "+
      "large %^GREEN%^coral%^RESET%^ reef growing here, creating a habitat for "+
      "various creatures on display.  %^MAGENTA%^C%^YELLOW%^o%^CYAN%^l%^ORANGE%^"+
      "o%^RED%^r%^GREEN%^f%^BLUE%^u%^%^MAGENTA%^l%^RESET%^ fish dart in and out "+
      "of the reef all the time appearing and hiding from view.  Small kids tug on"+
      " the sleeves of their parents and point at you swimming in the tank.\n");
    set_exits( ([ "west" : ROOMS"tank5",
	"south" : ROOMS"tank9" ,
	"north" : ROOMS"tank11" ]) );
    set_items( ([ "coral": "It really looks real.  And the fish appreciate it too.",
	"reef": "It really looks real.  And the fish appreciate it too.", 
	"kid":"He's trying to get his mom's attention and pointing at you!  Maybe he wants to swim too?.", 
	"wall":"You can see lots of people looking at you on the other side.",
	"fish": "They sure are %^CYAN%^c%^YELLOW%^o%^MAGENTA%^l%^ORANGE%^"+
	"o%^RED%^r%^GREEN%^f%^BLUE%^u%^%^MAGENTA%^l%^RESET%^ as they dart about."]) );
}
void reset() {
    int num_of_mobs = random(MAX_MOB_IN_ZONE)+1;
    int mob_num;
    int i;

    ::reset();
    if(!present("monster")) {
	for (i=0;i<num_of_mobs;i++){
	    mob_num=random(AQUA_MOBS);
	    switch (mob_num){
	    case 0:
		new(MOB"ray")->move(this_object());
		break;
	    case 1:
		new(MOB"jellyfish")->move(this_object());
		break;
	    case 2:
		new(MOB"slug")->move(this_object());
		break;
	    case 3:
		new(MOB"dolphin")->move(this_object());
		break;
	    case 4:
		new(MOB"hippocampus")->move(this_object());
		break;
	    case 5:
		new(MOB"diver")->move(this_object());
		break;
	    default:;
	    }             
	}
    }
}
