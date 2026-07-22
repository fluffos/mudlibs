/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("披风"NOR, ({"aimi pifeng", "hecheng", "pifeng"}) );
	set("hcloth/name", "披风"NOR);
	set("hcloth/id", "aimi pifeng");
	set("long", "这是由艾米(aimi)合成的披风" + NOR + "。\n");
	set("armor_type", "pifeng");
	set_weight(5000);
	set("unit", "件");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 176);
	set("armor_prop/constitution", 590);
	set("armor_prop/dexerity", 633);
	set("armor_prop/intelligence", 595);
	set("armor_prop/strength", 584);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

