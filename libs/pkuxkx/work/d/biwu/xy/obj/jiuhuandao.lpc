// jiuhuandao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	    set_name(HIG"泼风九环刀"NOR, ({ "jiuhuan dao", "dao", "blade" }) );
	    set_weight(5000);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "把");
				set("value", 1);
				set("material", "iron");
				set("long", "这是一把沉甸甸的九环大刀。\n");
				init_blade(85);
				setup();
			}
}
