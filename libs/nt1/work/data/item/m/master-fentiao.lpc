// SN:@S_b68_2oK^=2[cc
// ITEM Made by player(殷正廉:master) /data/item/m/master-fentiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon May 10 18:36:55 2004
#include <ansi.h>
#include <weapon.h>

inherit WHIP;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m红莲老祖[1;37m的[1;35m粉条[2;37;0m", ({ "fentiao" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "根");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一根鞭。
[1;37m一根从红莲老祖那里弄成的鞭子。[2;37;0m
鞭柄上刻着一行小字：殷正廉(master)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "[36m$N偷偷的跑到红莲老祖背后，突然从他的鼻孔里面抽出一条黏糊糊的液体，\n然后“啪”的一声，甩到墙上晾干，最后用点吹风吹干，居然做成了$n！！！[2;37;0m\n");
	set("unwield_msg", "[36m$N把$n[36m往天上一抛，顺势跳开，$n[36m在天上转了几个\n圈，然后急速落下，“啪”的一声后，裂成数段，消失了……[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_whip(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
