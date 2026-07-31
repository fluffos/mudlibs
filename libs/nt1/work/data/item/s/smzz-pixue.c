// SN:3V16VQOI]W=mfO;Z
// ITEM Made by player(张无忌:smzz) /data/item/s/smzz-pixue.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Mon Jul 12 20:34:49 2004
#include <ansi.h>
#include <armor.h>

inherit BOOTS;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;34m教主[1;31m皮靴[2;37;0m", ({ "pixue" }));
	set_weight(420);
	set("item_make", 1);
	set("unit", "双");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一双靴子。
[1;37m一双用金丝绣成的教主专用[1;31m皮靴。据说穿上他可以实现[1;32m天地一日还。[2;37;0m
靴子缘上刻着一行小字：张无忌(smzz)
");
	set("value", 2100000);
	set("point", 156);
	set("material", "silk");
	set("wear_msg", "[1;37m一道闪电划破长空[1;31m一群身着红色火焰图案的[1;32m名教弟子\n[1;31m必恭必敬的为他们的教主穿上[1;34m教主[1;31m皮靴。[2;37;0m\n");
	set("remove_msg", "[1;37m一道闪电划破长空[1;31m一群身着红色火焰图案的[1;32m名教弟子\n[1;31m必恭必敬的为他们的教主换下[1;34m教主[1;31m皮靴。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());
	set("armor_prop/dodge", apply_armor() / 10 + 1);

	setup();
}

string long() { return query("long") + item_long(); }
