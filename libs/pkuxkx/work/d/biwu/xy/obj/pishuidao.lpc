// pishuidao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	    set_name(HIW"劈水刀"NOR, ({ "pishui dao", "dao", "blade" }) );
	    set_weight(4000);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "把");
				set("value", 1);
				set("material", "iron");
				set("long", "这是一把制作精良的劈水刀。\n");
				init_blade(65);
			}
	    setup();
}
