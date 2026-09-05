//bishuijian.c	碧水剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIG"碧水剑"NOR, ({ "bishui jian", "jian","sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是一把削铁如泥的宝剑，剑身发出绿油油的光芒，煞是好看。\n");
		set("value", 100000);
		set("mingjiao",1);
		set("material", "steel");
		set("wield_msg", GRN"只见绿光一闪，$N手中多了一把" + HIG "碧水剑" NOR + "。\n");
		set("unwield_msg", GRN"绿光闪过之后，" + HIG "碧水剑" NOR + "已被$N插回鞘中。\n"NOR);
	}
	init_sword(100);
	setup();
}
