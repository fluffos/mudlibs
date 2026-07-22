/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("项链"NOR, ({"bbzz neck", "hecheng", "neck"}) );
	set("hcloth/name", "项链"NOR);
	set("hcloth/id", "bbzz neck");
	set("long", "这是由本副(bbzz)合成的项链" + NOR + "。\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "个");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 428);
	set("armor_prop/constitution", 641);
	set("armor_prop/dexerity", 654);
	set("armor_prop/intelligence", 821);
	set("armor_prop/strength", 734);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

