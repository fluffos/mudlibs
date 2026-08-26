#include <std.h>
#include "../../serakii.h"


inherit VAULT;

void create(){
   ::create();
   set_property("indoors",1);
   set_property("light",2);
   set_name("small second floor landing");
   set_short("%^C094%^small second floor landing%^CRST%^");
   set_long("%^C058%^At the top of the %^C059%^stairs "+
   "%^C058%^is a small landing. The sounds from the inn "+
   "below are muted here though the smell of %^C102%^cooking "+
   "%^C058%^and %^C059%^wood smoke%^C058%^ still permeates "+
   "the air. The ceiling here is sloped from the pitched "+
   "roof. Two doors lead to guest rooms.%^CRST%^\n");

set_items(([

		({"walls","wall"}) : "%^C246%^The walls "+
	   "are formed from %^C243%^giant stone "+
	   "blocks%^C246%^. They are thick and strong "+
	   "enough to protect you from anything "+
	   "happening outside.%^CRST%^\n",
       ({"sconces","crystals"}) : "%^C242%^Iron "+
	   "sconces%^C246%^ line the walls at regular "+
	   "intervals, filled with %^C092%^sma%^C165%^"+
	   "l%^C092%^l glow%^C165%^i%^C092%^ng cryst%^C165%^"+
	   "a%^C092%^ls%^C056%^ %^C246%^that fill the "+
	   "room with %^C165%^g%^C093%^e%^C165%^ntle lig%^C093%^h%^C165%^t%^C246%^.%^CRST%^\n%^CRST%^",
]));

set_smell("default","%^C058%^You smell %^C125%^"+
"rich food%^C058%^ and %^C094%^wood fire%^CRST%^");
set_listen("default","%^C061%^You hear %^C063%^constant "+
"conversation%^C061%^ from down below%^CRST%^");



    set_exits(([
                   "down" : INN"darts",
				   "white" : INN"white",
				   "red" : INN"red",
        ]));

    set_door("white door", INN"white", "white",0);
	set_door_description("white door","%^C252%^This door has been painted white%^CRST%^");
	
	    set_door("red door", INN"red", "red",0);
	set_door_description("red door","%^C160%^This door has been painted red%^CRST%^");


}
