#include <weapon.h>
#include <ansi.h>
inherit SWORD;
void create()
{
    set_name(HIR"雉尾剑"NOR, ({"sword","jian" }) );
    set_weight(7500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                set("no_put",1);
                set("no_zm",1);
                set("value", 50000);
                set("material", "iron");
        	set("long", "这是一把又细又长的剑，剑身锐利。");
        	set("wield_msg","一道红光闪过，$N手中已多了把$n。\n");
        	set("unwield_msg", "$N放下手中的$n。\n");
	}
        init_sword(120);
	setup();
}
