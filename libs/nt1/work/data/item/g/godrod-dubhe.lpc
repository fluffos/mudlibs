// SN:5SbjalHd@MkU=`;b
// ITEM Made by player(断武:godrod) /data/item/g/godrod-dubhe.c
// Written by GAN JIANG(Doing Lu 1998/11/2)	Tue Aug 26 22:26:14 2003
#include <ansi.h>
#include <armor.h>

inherit CLOTH;
inherit F_ITEMMAKE;

void create()
{
	set_name("[1;37m天枢长袍[2;37;0m", ({ "dubhe" }));
	set_weight(1400);
	set("item_make", 1);
	set("unit", "件");
	set("long", "这是由[1;37m冰蚕丝[2;37;0m炼制而成的一件战衣。
正星，主阴德，天子之象也。贪狼为其星居名。[2;37;0m
战衣缘上刻着一行小字：断武(godrod)
");
	set("value", 2100000);
	set("point", 262);
	set("material", "silk");
	set("wear_msg", "$n[1;36m散出一股仙气窜向[1;37m$N[1;36m的四肢百骸，随之一冲天际，却见[1;37m北极之星[1;36m隐隐地闪耀著[1;33m光辉[1;36m！[2;37;0m\n");
	set("remove_msg", "[33m$N[33m脱下了[1;37m天枢长袍[2;37;0m[33m。[2;37;0m\n");
	if (! check_clone()) return;
	restore();
	set("armor_prop/armor", apply_armor());

	setup();
}

string long() { return query("long") + item_long(); }
