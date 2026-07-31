// SN:9BGnKddgQ4heF=j^
// ITEM Made by player(流风:liufeng) /data/item/l/liufeng-zhuyun.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Wed Jan  7 08:13:06 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("猪猪[2;37;0m", ({ "zhuyun" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
星宿派第二代传人「[1;31m现在开始转运了真好[2;37;0m」猪猪[2;37;0m
剑柄上刻着一行小字：流风(liufeng)
");
	set("value", 2100000);
	set("point", 220);
	set("material", "magic stone");
	set("wield_msg", "[36m$N对著$n[36m「哈哈哈」大笑几声。[2;37;0m\n");
	set("unwield_msg", "[36m$N张大眼奇怪地瞪著$n[36m，慢慢地咧开嘴，捧腹大笑起来。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
