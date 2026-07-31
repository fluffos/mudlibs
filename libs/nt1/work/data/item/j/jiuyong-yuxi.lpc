// SN:>aohQ73hH2CT2Y3\
// ITEM Made by player(慕容复燕:jiuyong) /data/item/j/jiuyong-yuxi.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Jun 20 11:16:34 2004
#include <ansi.h>
#include <weapon.h>

inherit BLADE;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;33m玉玺[2;37;0m", ({ "yuxi" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "把");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一把刀。
[1;33m这是大燕国传国玉玺，拥有它就拥有了大燕国！[2;37;0m
刀柄上刻着一行小字：慕容复燕(jiuyong)
");
	set("value", 2100000);
	set("point", 436);
	set("material", "magic stone");
	set("wield_msg", "[1;33m大燕国的列祖列宗，助我完成复燕心愿吧！[2;37;0m\n");
	set("unwield_msg", "[1;33m$N小心翼翼的收起玉玺。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_blade(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
