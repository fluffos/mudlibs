// SN:oDh^iLoc_8d>QdnF
// ITEM Made by player(慕容新月:xinyue) /data/item/x/xinyue-staff.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jul 25 01:12:20 2004
#include <ansi.h>
#include <weapon.h>

inherit STAFF;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m只是当时已惘然[2;37;0m", ({ "staff" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根杖。
[1;34m一根青蓝色的竹棒，据说是由一种名为“鬼竹”的稀世竹子所制成，韧性十足，怎么弯曲都不会折断。[2;37;0m
杖柄上刻着一行小字：慕容新月(xinyue)
");
	set("value", 2100000);
	set("point", 786);
	set("material", "magic stone");
	set("wield_msg", "[1;34m$N抽出一根青蓝色的竹棒握在手中，之后就怔怔地站在那里，不言不语，神情说不出的惆怅和迷惘。\n这时鬼竹的真正魅力发挥了作用，它刺激在场的每一个人，大家心底最深处埋藏的情意都被激发出来，往事历历在目。[2;37;0m\n");
	set("unwield_msg", "[1;34m$N放下了手中那根竹棒，神情恢复常态，鬼竹的奇异魅力也随之收了回来。\n刚才的众人仿佛自梦中惊醒，看了看四周，却发现自己的脸上居然挂着久违了的泪滴，一脸的诧异，也是一脸的迷惑。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_staff(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
