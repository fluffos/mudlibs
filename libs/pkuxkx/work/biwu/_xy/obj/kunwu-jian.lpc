// 昆吾剑
// created by zine 25 Aug 2010
#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{
        set_name(HIW"昆吾剑"NOR,({ "kunwu jian", "jian", "sword" }) );
        set_weight(1200);
		if( clonep() )
                set_default_object(__FILE__);
        else 
			{
				set("unit", "柄");
				set("value", 1);
				set("material", "steel");
				set("long", "这是一柄通体泛着白光的剑，似乎十分锋利。\n");
				init_sword(65);
			}
        setup();
}
