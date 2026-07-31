// SN:9_4j]KNBi7_0=JF`
// ITEM Made by player(猪猪快跑:tiantian) /data/item/t/tiantian-biana.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Sep  6 13:17:17 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;35m九龙沧潇[2;37;0m", ({ "biana" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根鞭。
[1;35m九龙奔腾而至，化作一道长虹，顿时天地间一片苍凉[2;37;0m
鞭柄上刻着一行小字：猪猪快跑(tiantian)
");
	set("value", 2100000);
	set("point", 223);
	set("material", "magic stone");
	set("wield_msg", "[1;35m$N轻轻地手中一按，一道彩虹飞过，顿时化作万千闪电，清吟不已[2;37;0m\n");
	set("unwield_msg", "[1;35m$N隐去手中的九龙沧潇，龙啸顿时呼风而去，\n慢慢消失于遥远的天际尽头[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
