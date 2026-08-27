#include "path.h"
inherit CITYROOM;

#define NUM 1

void setup()
{
 set_light(50);
 set_short("Delfen's tower");
 set_long("You have followed Wall Street to its end, and are now standing "+
          "just below the tower of Delfen, the mightiest mage in the city.  "+
          "You may enter the tower or return south to the city streets.\n");

 add_exit("south", ROOM+"wall14","road");
 add_exit("up", ROOM+"mu","stairs");
 modify_exit("up", ({"message","N$N walks up into the tower.\n"}));
 add_item("tower", "It looks like a mighty Wizard's tower.\n");
 add_alias("tower", "delfen's tower");
 set_zone("city");
 set_monster(NUM, "city");
}
