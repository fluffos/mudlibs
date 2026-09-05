// 太阿剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{	
	set_name(HIY"太阿剑"NOR,({ "taie jian", "jian", "sword" }) );
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
