/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("戒指"NOR, ({"bbzz boots", "hecheng", "boots"}) );
	set("hcloth/name", "戒指"NOR);
	set("hcloth/id", "bbzz boots");
	set("long", "这是由本副(bbzz)合成的戒指" + NOR + "。\n");
	set("armor_type", "boots");
	set_weight(5000);
	set("unit", "双");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 205);
	set("armor_prop/constitution", 603);
	set("armor_prop/dexerity", 613);
	set("armor_prop/intelligence", 597);
	set("armor_prop/strength", 621);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

