/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
	object me = this_player();

	set_name("布衣"NOR, ({"benben cloth", "hecheng", "cloth"}) );
	set("hcloth/name", "布衣"NOR);
	set("hcloth/id", "benben cloth");
	set("long", "这是由本本(benben)合成的布衣" + NOR + "。\n");
	set("armor_type", "cloth");
	set_weight(5000);
	set("unit", "件");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 337);
	set("armor_prop/constitution", 685);
	set("armor_prop/dexerity", 691);
	set("armor_prop/intelligence", 763);
	set("armor_prop/strength", 766);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

