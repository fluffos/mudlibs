// 蓝玉剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(BLU"蓝玉剑"NOR,({ "lanyu jian", "jian", "sword" }) );
        set_weight(1200);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "柄");
				set("value", 1);
				set("material", "steel");
				set("long", "这是柄蓝玉剑，剑身上的蓝光若隐若现，锋利无比。\n");
				init_sword(55);
			}
        setup();
}
