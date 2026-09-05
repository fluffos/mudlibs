// staff
// created by zine

#include <weapon.h>
inherit STAFF;

void create()
{
	string * pre=({"亮银盘龙","八龙神火","铁黎蟠龙","齐眉乌金",});
	set_name(pre[random(sizeof(pre))]+"棍", ({ "staff","zhang"}));
    set_weight(3300);
	if( clonep() )
		 set_default_object(__FILE__);
    else 
		{
			set("unit", "根");
			set("long", "这是一根沉甸甸的棍子。\n");
			set("value", 1);
			set("material", "steel");
			init_staff(75+random(15));
		}
	setup();
}
