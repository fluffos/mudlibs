// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.

#include <weapon.h>
#include <ansi.h>
inherit BLADE;
void create()
{
	set_name(WHT"天机量衡尺"NOR, ({ "tianjichi" }) );
	set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("jungle",1);
		set("material", "iron");
		set("long", "天机量衡尺--这是武林人物梦寐以求的神兵，传说它能带给人最大的力量，才智
和运气。不过看起来没什么特别，只是白玉一块，也不是特别的锋利，比较特殊的就是入手温凉。\n");
		set("wield_msg", "忽然天空暗了一暗，接着似乎有道闪电闪了一闪，远方隐约传来一声龙吟。
这时$N已经把$n握在手中。\n");
                set("weapon_prop/intelligence",10);
                set("weapon_prop/strength",10);
                set("weapon_prop/karma",10);
                set("unequip_msg", "$N将手中的$n插入腰间，似乎天空又明亮了一点。\n");
	}
	init_blade(120);
	setup();
}

