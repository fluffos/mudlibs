// guitoudao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	    set_name(RED"三叉鬼头刀"NOR, ({ "guitou dao", "dao", "blade" }) );
	    set_weight(4000);
		if( clonep() )
                set_default_object(__FILE__);
		else 
			{
				set("unit", "把");
				set("value", 1);
				set("material", "iron");
				set("long", "这是一把充满杀气带着血色的三叉鬼头刀。\n");
				init_blade(65);
			}
	    setup();
}
