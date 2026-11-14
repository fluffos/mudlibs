  /* Coded by Charity 6/25/95 */
inherit "std/room";
#include "path.h"
#include <rooms.h>
#include <moving.h>
    
    
    
create() {
 ::create();
 SetIntShort("The Nightfall Operahouse Entrance Way");
 SetIntLong(
"The inside of this room is ornately decorated, and is clearly a high "
"class place. No ordinary street rabble here. A gentleman in a tuxedo "
"sells tickets to customers. He lets his friends in for free though. "
"There is a coat closet where he will check your coat, off to one side. "
"There is a framed picture on the wall. A large double door west leads into "
"the main hall. The door to the east will take you back outside. A flight "
"of stairs lead up to the balcony.\n");
 SetIndoors(1);
     
AddExit("east",CITY("shouse"));
AddExit("west",OPERA("mainhall"));
AddExit("up",OPERA("balcony"));
AddItem(MONSTER("zeek"),REFRESH_DESTRUCT);
AddDetail("lights","This hall is well lit by wall sconces.\n");
AddDetail("wall sconces","Fancy wall mounted lamps. \n");
AddDetail("sconces","Fancy wall mounted lamps. \n");
AddDetail("double door","The doors are made of very fine mahogany. They lead into the main hall. \n");
AddDetail("double doors","The doors are made of very fine mahogany. They lead into the main hall. \n");
AddDetail("door","The doors are made of very fine mahogany.\n");
AddDetail("floor","It's a thick, plush carpet, and feels good to your feet.\n");
AddDetail("carpet","It's a thick and plush carpet. It mush have cost a lot of money.\n");
AddDetail("ceiling","High above you is the ceiling.\n");
AddDetail("coats","You can only see that they are nice coats.\n");
AddDetail("coat closet","There are many coats hung up on hangers.\n");
AddDetail("closet","There are many coats hung up on hangers.\n");
AddDetail("hangers","Metal things upon which coats may be hung. \n");
AddDetail("stairs","Carpeted stairs which lead up to the balcony.\n");
AddDetail("picture","The picture is of a woman named Charity, the Opera Hall Founder.\n");
SetIntNoise("You can hear the beautiful singing coming from the opera hall.\n");
}
