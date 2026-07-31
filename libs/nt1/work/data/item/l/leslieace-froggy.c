// SN:K\Bl1KlFlSI2VVUI
// ITEM Made by player(南宫图:leslieace) /data/item/l/leslieace-froggy.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Thu Dec  4 17:05:05 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;32m青蛙披风[2;37;0m", ({ "froggy" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
战衣缘上刻着一行小字：南宫图(leslieace)
");
	set("value", 2100000);
	set("point", 280);
	set("material", "silk");
	set("wear_msg", "[1;36m难道这就是传说中的[1;35m☆[1;32m青蛙披风[1;35m☆[1;36m！？[2;37;0m\n");
	set("remove_msg", "[1;36m难道这就是传说中的[1;35m☆[1;32m青蛙披风[1;35m☆[1;36m！？[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
