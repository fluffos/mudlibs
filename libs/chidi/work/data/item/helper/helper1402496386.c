/**本文件由合成系统自动生成**/

#include <ansi.h>
#include <armor.h>

inherit NECK;

void create()
{
	object me = this_player();

	set_name("南方焰光旗"NOR, ({"helper neck", "hecheng", "neck"}) );
	set("hcloth/name", "南方焰光旗"NOR);
	set("hcloth/id", "helper neck");
	set("long", "这是由飞雪连天(helper)合成的南方焰光旗" + NOR + "。\n");
	set("armor_type", "neck");
	set_weight(5000);
	set("unit", "个");
	set("no_get", 1);
	set("no_give", 1);
	set("no_sell", 1);
	set("no_steal", 1);
	set("no_beg", 1);
	set("no_drop", 1);
	set("armor_prop/armor", 1174);
	set("armor_prop/constitution", 1134);
	set("armor_prop/dexerity", 1214);
	set("armor_prop/intelligence", 6293);
	set("armor_prop/strength", 1363);
	set("wear_msg", me->name() + NOR "装备" + name () + NOR "！\n");
	set("unwear_msg", me->name() + NOR "脱下" + name () + NOR "！\n");

   setup();
}

