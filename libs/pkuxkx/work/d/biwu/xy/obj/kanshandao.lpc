// kanshandao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	    set_name(HIY"金背大砍刀"NOR, ({ "dakan dao", "dao", "blade" }) );
	    set_weight(4000);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "把");
				set("value", 500);
				set("material", "iron");
				set("long", "这是一把两尺来长的大砍刀，刀光闪闪，入手极重。\n");
				init_blade(55);
				setup();
			}
}
