/*  -*- LPC -*-  */
//Example armour.
//Orig by Casper 9/95
#include <mudlib.h>
 
inherit ARMOUR;
 
void setup()
{
  add_ids( ({"chainmail", "chain", "mail", "suit of chainmail", "suit",
	    "armour", "armor"}) );
  set_short("a suit of chainmail");
  set_long("A suit of armour made from interlocking rings of metal,\n"
	   "heavy, but not a much so as plate, making it ideal for quick\n"
	   "incursions into battle.\n");

  set_weight(20);  // 20 lbs.
  set_bulk(4);  // who knows what these units are?
  set_value(({ 20, 1 }));   // worth 70 silver (?) -- Tim
  
  set_ac(100,8);  // makes 10% harder to hit, and reduces damage delivered by 8
  set_type("body2");  // 2 denotes for 2 armed creature.
}
