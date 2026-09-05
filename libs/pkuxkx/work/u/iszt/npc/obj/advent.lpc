// jitui.c 鸡腿

#include <weapon.h>

inherit DAGGER;
inherit F_FOOD;

void create()
{
        set_name("猪头行云", ({ "advent" }) );
        set_weight(10000000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "一位很猪头很猪头的巫师。\n");
                set("unit", "个");
                set("value", 1);
                set("food_remaining", 10);
                set("food_supply", 1);
                set("wield_msg", "$N抓起一个$n，握在手中当武器。\n");
                set("material", "bone");
	}
        init_dagger(1);
	setup();
}

int finish_eat()
{
	if( !query("weapon_prop") ) return 0;
        set_name("啃得精光的猪头行云", ({ "bone" }) );
        set_weight(2147000000);
        set("long", "猪头行云的头盖骨，好恐怖啊！\n");
	return 1;
}
