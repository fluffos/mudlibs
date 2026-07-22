#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIG"青锋剑"NOR, ({"sword","jian" }) );
    set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                set("no_put",1);
                set("no_zm",1);
                set("value", 10000);
                set("material", "iron");
        	set("long", "这是一把又细又长的剑，剑身锐利。");
        	set("wield_msg","一道青光闪过，$N手中已多了把$n。\n");
        	set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_sword(100);
	setup();
}
