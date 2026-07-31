// SN:LWj6dl4W5b;\0BHd
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-hammer.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 25 03:05:27 2004
#include <ansi.h>
#include <weapon.h>

inherit HAMMER;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m八千里路云和月[2;37;0m", ({ "hammer" }));
	set_weight(21000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把锤。
[1;34m这是一柄巨大的锤子，乃当年岳爷爷的儿子岳云所用，锤身透出一股悲壮苍凉之意。[2;37;0m
锤柄上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 786);
	set("material", "magic stone");
	set("wield_msg", "[1;34m$N愤怒欲狂，泪湿青衫，举起一柄巨大的锤子－－号曰$n[1;34m，容色坦荡，朝着面前的卑鄙小人锤去。\n轰然一声巨响，那厮已被锤个正着，直挺挺的陷入了泥土中。$N仰天长啸：岳元帅，今日我为世间除此獠。[2;37;0m\n");
	set("unwield_msg", "[1;34m$N见周围的宵小俱被$n[1;34m的威严所震慑，一个个战战兢兢，不敢再为恶，便收回了手中的神锤。\n$N长叹道：昔日岳元帅八千里追逐驰骋，眼中所见只是那天上的云和月，如此英雄为何苍天竟不庇佑？[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_hammer(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
