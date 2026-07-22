/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("盘古钟"NOR, ({"helper head", "hecheng", "head"}) );
	set("hcloth/name", "盘古钟"NOR);
	set("hcloth/id", "helper head");
	set("long", "这是由飞雪连天(helper)合成的盘古钟" + NOR + "。\n");
	set("armor_type", "head");
	set_weight(5000);
	set("unit", "双");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 858);
	set("armor_prop/constitution", 1140);
	set("armor_prop/dexerity", 1016);
	set("armor_prop/intelligence", 6088);
	set("armor_prop/strength", 1253);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

