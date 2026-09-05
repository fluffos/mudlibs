//riyuedao 日月神刀
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIR"日月神刀"NOR, ({ "riyue dao", "dao","blade" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是日月神教的圣物之一。据说它在日月教徒手中能发挥出更大的威力。\n");
		set("value", 10000);
		set("mingjiao",1);
        set("rigidity", 500);
 		set("material", "steel");
		set("wield_msg", GRN"只听「噌」的一声，$N手中多了一把明晃晃的" + HIR "日月神刀\n" NOR);
		set("unwield_msg", GRN"$N手腕一翻，将" + HIR "日月神刀" NOR + "插回鞘中。\n"NOR);
	}
	init_blade(150);
	setup();
}
