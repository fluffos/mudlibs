// jiandao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	    set_name(YEL"剪刀"NOR, ({ "jian dao", "dao", "jian zi" }) );
	    set_weight(400);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "把");
				set("value", 1);
				set("material", "iron");
				set("long", "一把锈迹斑斑的剪刀。\n");
				init_blade(1);
			}
	    setup();
}
