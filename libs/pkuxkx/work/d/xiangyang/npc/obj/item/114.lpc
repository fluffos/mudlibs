//yxbj.c 游侠宝剑
// by paladin

#include <weapon.h>
#include <ansi.h>
inherit SWORD;

void create()
{int pp;
set_name( MAG"游侠宝剑" NOR, ({ "paladin sword", "jian" }) );
set_weight(100000);

        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "柄");
		set("long", "这是一把游侠早年闯荡江湖时炼就的宝剑.\n");
		set("value", 10000);
                set("material", "steel");
                set("rigidity", 500);
		set("wield_msg", "$N把宝剑拔出剑鞘, 耀眼的光芒照亮了周围的一切.\n");
		set("unwield_msg", "$N将剑插回剑鞘, 天空顿时暗淡下来.\n");
}
	pp=100+random(100);

	init_sword(pp);
                setup();
}
