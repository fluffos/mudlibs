#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
 ::create();
   set_properties(([ "town" : 1, "light" : 2, "night light" : 1,
     "forest" : 1 ]));
   set_short("A well tended garden");
   set_day_long("Breath taking displays of flowers and trees have been "
     "carefully laid out within the small garden, flooding the viewer "
     "all at once. Among the flowers are many different colored roses, "
     "water lillies in a small pond, and golden sunflowers. A hedge has "
     "been cut out in the form of a bear next to the door of the house. "
     "A house rests right at the end of the garden. A walkway leads east "
     "onto a road.");
   set_night_long("Shadows of flowers and trees are all that can be made "
     "out of a well-arranged scenery within this garden. Many fresh and "
     "wonderous smells flood the entire area, especially that of the "
     "many flowers. Flower beds have been laid out and some sort of "
     "was put near the door to the house here. A walkway is nearly "
     "hidden, leading to the road.");
   set_smell("default",  "The fragrance of many flowers fills the air.");
   set_items(([
   ]));
   set_exits(([ "enter" : ROOMS"house1",
                "east" : ROOMS"stown5" ]));
}

void reset() {
 ::reset();
   if (!present("rose")) {
     switch(random(6)) {
       case 1:
         make(OBJ"rose/orange");
         break;
       case 2:
         make(OBJ"rose/red");
         break;
       case 3:
         make(OBJ"rose/pink");
         break;
       case 4:
         make(OBJ"rose/purple");
         break;
       case 5:
         make(OBJ"rose/yellow");
         break;
       case 6:
         make(OBJ"rose/white");
         break;
       default:
         make(OBJ"rose/white");
     }
   }
}
