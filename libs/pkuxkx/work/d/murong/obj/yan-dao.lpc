//燕翎刀
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(HIG"燕翎刀"NOR, ({ "yanling dao", "dao","yanling" }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是曼陀山庄祖传的宝刀。\n");
                  set("value", 12000);
		set("material", "steel");
		set("wield_msg", GRN"只听「噌」的一声，绿光四射，$N手中多了一把明晃晃的" + HIG "燕翎刀\n" NOR);
		set("unwield_msg", GRN"$N手腕一翻，将" + HIR "燕翎刀" NOR + "插回鞘中。\n"NOR);
	}
           init_blade(135);
	setup();
}
