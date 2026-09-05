// 锄头
// created by zine

#include <weapon.h>
inherit STAFF;

void create()
{
	set_name("锄头", ({ "chu tou","chutou"}));
    set_weight(3300);
	if( clonep() )
		 set_default_object(__FILE__);
    else 
		{
			set("unit", "把");
			set("long", "这是一把农夫常用的锄头。\n");
			set("value", 1);
			set("material", "steel");
			init_staff(random(15));
		}
	setup();
}
