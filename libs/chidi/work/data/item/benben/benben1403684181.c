/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("布带"NOR, ({"benben waist", "hecheng", "waist"}) );
	set("hcloth/name", "布带"NOR);
	set("hcloth/id", "benben waist");
	set("long", "这是由本本(benben)合成的布带" + NOR + "。\n");
	set("armor_type", "waist");
	set_weight(5000);
	set("unit", "条");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 391);
	set("armor_prop/constitution", 653);
	set("armor_prop/dexerity", 751);
	set("armor_prop/intelligence", 687);
	set("armor_prop/strength", 742);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

