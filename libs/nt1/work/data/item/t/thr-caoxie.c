// SN:1Bh[8V\gemjGm>5f
// ITEM Made by player(阿二:thr) /data/item/t/thr-caoxie.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Oct  9 04:44:56 2003
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m草鞋[2;37;0m", ({ "caoxie" }));
	set_weight(1080);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[33m乌金丝[2;37;0m炼制而成的一双靴子。
阿二穿得很臭的草鞋。[2;37;0m
靴子缘上刻着一行小字：阿二(thr)
");
	set("value", 1500000);
	set("point", 47);
	set("material", "silk");
	set("wear_msg", "$N先跷起一只泥脚杆，将一只臭烘烘的草鞋穿上\n接着她抬起另一只脚，穿上一只更臭的鞋子。[2;37;0m\n");
	set("remove_msg", "$N一不小心踩到了自己的脚跟，骂了一句脏话走了。\n\n突然你发现，$N的鞋子掉了下来，快拣这双宝贝回去熬汤吧！\n[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/dodge", apply_armor() / 10 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
