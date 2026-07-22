/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("子鞋"NOR, ({"linzi boots", "hecheng", "boots"}) );
	set("hcloth/name", "子鞋"NOR);
	set("hcloth/id", "linzi boots");
	set("long", "这是由林子(linzi)合成的子鞋" + NOR + "。\n");
	set("armor_type", "boots");
	set_weight(5000);
	set("unit", "双");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 332);
	set("armor_prop/constitution", 787);
	set("armor_prop/dexerity", 732);
	set("armor_prop/intelligence", 760);
	set("armor_prop/strength", 833);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

