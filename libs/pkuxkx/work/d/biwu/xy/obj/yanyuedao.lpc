// yanyuedao.c
// credited by zine 25 Aug 2010

#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{	
	set_name(HIC"青龙偃月刀"NOR, ({ "yanyue dao", "dao", "blade" }) );
	set_weight(14000);
	if( clonep() )
		set_default_object(__FILE__);
    else 
		{
			set("unit", "把");
			set("value", 500);
			set("material", "iron");
			set("long", "这是一把青龙偃月刀，传说中是武帝关公的兵器。\n");
			init_blade(85);
		}
	setup();
}
