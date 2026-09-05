// 鱼肠剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
	set_name(WHT"鱼肠剑"NOR,({ "yuchang jian", "jian", "sword" }) );
    set_weight(1200);
	if( clonep() )
		set_default_object(__FILE__);
	else 
		{
			set("unit", "柄");
			set("value", 1);
			set("material", "steel");
			set("long", "这是一柄传说中的剑，异常锋利。\n");
            init_sword(85);
		}
	setup();
}
