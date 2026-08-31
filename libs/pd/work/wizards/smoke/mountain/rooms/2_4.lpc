#include <std.h>

inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
 set_short("Inside a mountain");
 set_long("Shadows dance along the walls from the south. Arcane "
          "paintings adorn the cave walls. Some grass grows here but is "
          "covered in frost.");
 set_listen("default", "An annoying chirping can be heard nearby.");
    set_items(([
({"fire", "campfire"}) : "There is a campfire burning, fueled by timber " 
         "from the exterior of the mountain. There is no telling who "
	"or what set the fire.",
({"shadows"}) : "Shadows flicker wildly along the walls, creating some inter"
         "esting lighting effects.",
({"walls", "paintings", "arcane paintings"}) : "The rock formations inside "
	"the cavern are covered in arcane symbols. They seem to be in an "
         "indistinctive language, but certainly don't look inviting.",
({"grass", "frost"}) : "Patches of %^GREEN%^grass%^RESET%^ grow randomly through"
         "out this portion of the cavern.",   
({"nest"}) : "High atop the rock that makes up the eastern wall is a birds"
         "nest."
    ]));
    set_exits( ([ 
       "south" :  "/wizards/smoke/mountain/rooms/2_3",
       "north" :  "/wizards/smoke/mountain/rooms/2_5"
    ]) );
}
void reset() {
    if(!present("ogre"))
        new("/wizards/smoke/mountain/monsters/owarrior")->move(this_object());
        new("/wizards/smoke/mountain/monsters/owarrior")->move(this_object());
        new("/wizards/smoke/mountain/monsters/oshaman")->move(this_object());
}
