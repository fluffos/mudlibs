//riyuejian 日月神剑
#include <ansi.h>
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name(HIG"日月神剑"NOR, ({ "riyue jian", "jian","sword" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
		set("long", "这是日月神教的圣物之一。据说它在日月教徒手中能发挥出更大的威力。\n");
		set("value", 10000);
		set("mingjiao",1);
        set("rigidity", 500);
 		set("material", "steel");
		set("wield_msg", GRN"$N从剑鞘中拔出一柄" + HIG "日月神剑" NOR + "，握在手中，轻轻一弹，发出「嗡嗡」的声音。\n"NOR);
		set("unwield_msg", GRN"$N舞了个剑花，将" + HIG "日月神剑" NOR + "插回鞘中。\n"NOR);
	}
        init_sword(120);
	setup();
}
