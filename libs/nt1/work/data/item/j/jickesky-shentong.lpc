// SN:<S[5<gUQ8:em2c?f
// ITEM Made by player(一可行:jickesky) /data/item/j/jickesky-shentong.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Sep  2 15:22:06 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;31m神通剑[2;37;0m", ({ "shentong" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
[1;31m天兵神通，走势要平善，气要随行，两眼顾尖，气沉两足稳，
身法需自然，身行如飞燕，身落如停风，收如花絮，刺如钢钉！[2;37;0m
剑柄上刻着一行小字：一可行(jickesky)
");
	set("value", 2100000);
	set("point", 243);
	set("material", "magic stone");
	set("wield_msg", "[1;37m将手一挥，一柄[1;31m神通剑[1;37m从身后飞出，电光一闪，已经握在了你手中。[2;37;0m\n");
	set("unwield_msg", "[1;37m将[1;31m神通剑[1;37m随手一扔，只见[1;31m神通剑[1;37m突然变得火红，化做无数的火星四散飘走了！[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
