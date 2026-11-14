#include "path.h"
inherit "/room/pub";

create(){
  ::create();
  SetIntLight(10);
  SetIntShort("bar");
  SetIntLong(
"This is a nice old rustic bar.  It is a dedication to remembering "
"the way Nightfall used to be.  Over the bar you can see a picture "
"of Phish.  You can read the menu behind the bar to see what classic "
"Nightfall drinks are available here.\n");
        AddDrink("special",10,8,10,0);
        AddDrink("coffee",0,2,-2,20);
        AddDrink("firebreather",25,20,12,140);
        AddDrink("beer",0,2,2,3);
  AddExit("east","./hall");
  AddDetail(({"bar","rustic bar"}),"A rustic bar.\n");
  AddDetail(({"picture","phish","Phish"}),
  "This is a picture of Phish, who built this castle.\n");
  AddDetail("menu", "You should read the menu.\n");
 }
