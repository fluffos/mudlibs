// cw_cloth
//by steel
#include "armor.h"
#include "ansi.h"
inherit CLOTH;
void create()
{	
        set_name(HIR"闯王战衣"NOR, ({ "cw_cloth", "cloth" }) );
	set_weight(6500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "件");
		set("long", "不用偶多说了吧，闯王穿过....呵呵。\n");
		set("material", "cloth");
		set("no_put", 1);
//		//set("value", 100000);
		set("armor_prop/armor", 300);
		set("armor_prop/defense", 10);	
   }	setup();
}