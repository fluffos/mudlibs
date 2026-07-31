// cw_hat
//by steel
#include "ansi.h"
#include "armor.h"
inherit HEAD;
void create()
{	
  set_name(HIR"闯王战盔"NOR, ({ "cw_hat", "hat" }) );
  set_weight(1000);	
   if( clonep() )
  set_default_object(__FILE__);
  else {
		set("unit", "顶");
		set("long", "这是闯王戴过的头盔，透出一股暗红色。\n");
		set("no_put", 1);
//		//set("value", 100000);
		set("armor_prop/attack", 20);
		set("armor_prop/armor", 250);	
     }	
                setup();
 } 