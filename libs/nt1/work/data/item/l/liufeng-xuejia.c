// SN:NPPM]^UTVX;0K\WI
// ITEM Made by player(流风:liufeng) /data/item/l/liufeng-xuejia.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Sun Nov  2 15:31:05 2003
#include <ansi.h>
#include <armor.h>

inherit ARMOR;
inherit F_ITEMMAKE;

void create()
{
	set_name("[2;37;0m[31m血穹苍[2;37;0m", ({ "xuejia" }));
	set_weight(9000);
	set("item_make", 1);
	set("unit", "张");
	set("long", "这是由[1;35m神铁[2;37;0m炼制而成的一张护甲。
是一件血的甲。。看起来有很多血在上面。。[2;37;0m
护甲缘上刻着一行小字：流风(liufeng)
");
	set("value", 2100000);
	set("point", 151);
	set("material", "magic stone");
	set("wear_msg", "[1;31m血穹苍不知道重哪里冒出来。。[2;37;0m\n");
	set("remove_msg", "[1;31m$N随手一丢把血穹苍丢在地上，可是甲突然消失了。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/parry", apply_armor() / 15 + 1);
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
