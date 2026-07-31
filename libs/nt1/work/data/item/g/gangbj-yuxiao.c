// SN:8HEA`<2@`SFQ8>j9
// ITEM Made by player(唐三藏:gangbj) /data/item/g/gangbj-yuxiao.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Oct 11 02:14:00 2004
#include <ansi.h>
#include <weapon.h>

inherit XSWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m碧玉箫[2;37;0m", ({ "yuxiao" }));
	set_weight(1800);
	set("item_make", 1);
	set("unit", "支");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一支箫。
箫柄上刻着一行小字：唐三藏(gangbj)
");
	set("value", 2100000);
	set("point", 100);
	set("material", "magic stone");
	set("wield_msg", "$N取出一只$n，好像要吹一曲的样子。[2;37;0m\n");
	set("unwield_msg", "$N将$n收入怀中。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_xsword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
