// SN:j]BgEBMh1^eN_J?>
// ITEM Made by player(韩子奇:hanz) /data/item/h/hanz-hansword.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Sep 12 11:35:27 2004
#include <ansi.h>
#include <weapon.h>

inherit SWORD;
inherit F_ITEMMAKE;

void create()
{
	set_name("承影剑[2;37;0m", ({ "hansword" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "柄");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一柄剑。
这把剑是有影无形的长剑，就是在《列子汤问》之中被列子激赏的铸于商朝后来被春秋时卫国人孔周所藏的名剑。[2;37;0m
剑柄上刻着一行小字：韩子奇(hanz)
");
	set("value", 2100000);
	set("point", 216);
	set("material", "magic stone");
	set("wield_msg", "只见$N双手合握之中是一截剑柄，只有剑柄不见长剑剑身，但是，在北面的墙壁上却隐隐投下一个飘忽的剑影，剑影只存片刻，就随着白昼的来临而消失[2;37;0m\n");
	set("unwield_msg", "只见$N扬起的双手划出一条优雅的弧线，承影剑又归于无形，暮色无声合拢，天地之间一片静穆。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	init_sword(apply_damage());

	setup();
}

string long() { return query("long") + item_long(); }
