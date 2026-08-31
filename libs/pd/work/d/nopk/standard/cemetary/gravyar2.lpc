#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
   ::create();
    set_property("light", 0);
    set("short", "Entrance to graveyard");
    set("long",
	"This is the entrance to an ancient and dark cemetary. Soft black dirt "
	"covers the ground, as well as many of the graves. A few patches of dead "
	"grass can be seen near a couple graves. Looking over the field of "
	"cracked marble headstones, like the one you stand near, a feeling of "
	"dread finds it's way into your gut. The grave here has been carelessly "
	"dug up.");
    set_items(
	(["depths" : "You look down into Melissa's grave and see "
	    "a swirling white haze.",
	  "haze" : "The haze moves like it is alive, and takes "
	    "on what looks like a female form at times.",
	  "haziness" : "The haziness swirls constantly and covers the grave.",
	  "depression" : "The depression is caused by the soil over "
	    "the grave sinking.  There is a haze covering it.",
	  "headstone" : "An ancient headstone, perhaps the first.  "
	    "Its writing is illegible except for the name Melissa Praxis.",
	  "graves" : "Most graves here are overgrown and untended. "
	    "You stand next to a very old and shabby, sunken grave.",
	  "cemetary" : "The residents of Tirun get buried there. "
	    "It looks spooky. Dread creaps into your heart.",
	  "grave" : "You look down at Melissa's grave.  "
	    "You see an odd haziness in the depths of the depression "
	    "where the grave has sunken over the years."]));
    set_exits( 
(["west" : "/d/nopk/tirun/cgate",
                "northeast" : ROOMS"cemetary/gravyar6",
                "east" : ROOMS"cemetary/gravyar5",
                "southeast" : ROOMS"cemetary/gravyar4",
                 "south" : ROOMS"cemetary/gravyar3",
                 "north"  : ROOMS"cemetary/gravyar8"]) );
}

int enter(string str) {
   if (!str || str != "grave") {
      message("info", "Enter what?", this_player());
      return 1;
   }
   this_player()->move_player(ROOMS"cemetary/grave", "grave");
   return 1;
}

void init() {
 ::init();
   add_action("enter", "enter");
}
