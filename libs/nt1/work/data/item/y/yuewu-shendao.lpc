// SN:@^GAJNha5ooE`HYe
// ITEM Made by player(红玄佛:yuewu) /data/item/y/yuewu-shendao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Oct 29 23:00:36 2003
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m一陀大便[2;37;0m", ({ "shendao" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;31m看起来臭哄哄的，卖相不怎么样[2;37;0m
刀柄上刻着一行小字：红玄佛(yuewu)
");
	set("value", 2100000);
	set("point", 149);
	set("material", "magic stone");
	set("wield_msg", "[1;32m只听噗的一声，$N拉出了[1;32m一陀大便[2;37;0m\n");
	set("unwield_msg", "[1;32m扑通，一陀大便掉在马桶之中，$N顿时感到舒服许多[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
