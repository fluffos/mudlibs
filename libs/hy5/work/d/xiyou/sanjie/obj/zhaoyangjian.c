//zhaoyaojian.c
#include <ansi.h>
#include <weapon.h>

inherit SWORD;

void create()
{
    set_name( HIC "朝阳剑" NOR, ({ "zhaoyang jian", "jian" }) );
    set_weight(4000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
        	set("unit", "柄");
                set("value", 10000);
//        	set("no_drop", "1");
        	set("material", "iron");
                set("long", "这是朝阳天师杀妖的利器，此乃缠身的极其轻便好软剑。\n");
        	set("wield_msg","剑身发青，寒光逼人，$n将在$N抽到手中，剑身不断鸣响。\n");
        	set("unwield_msg", "$N将$n抽回腰间，华光顿敛。\n");
				set("no_sell",1);
				set("no_drop","去垃圾堆丢吧，乱扔会污染环境!\n");
               	}
        init_sword(105);
	setup();
}
