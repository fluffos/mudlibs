// yanlingdao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{	set_name(CYN"雁翎刀"NOR, ({ "yanling dao", "dao", "blade" }) );
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
    else 
		{
			set("unit", "把");
			set("value", 1);
			set("material", "iron");
			set("long", "这是一把武林中人爱用的雁翎刀。\n");
			init_blade(55);
		}
	setup();
}
