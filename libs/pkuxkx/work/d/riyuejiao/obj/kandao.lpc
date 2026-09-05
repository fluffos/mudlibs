
#include <ansi.h>
#include <weapon.h>
inherit BLADE;

void create()
{
	set_name(YEL"砍刀"NOR, ({ "kan dao", }));
	set_weight(3000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long", "这是一把锈迹斑斑的砍刀，被人丢弃在这里。\n");
		set("value", 0);
		set("is_kandao",1);
        set("rigidity", 500);
 		set("material", "steel");
		set("wield_msg", GRN"只听「噌」的一声，$N手中多了一把砍刀。 \n" NOR);
		set("unwield_msg", GRN"$N手腕一翻，将砍刀插回腰间。\n"NOR);
	}
	init_blade(5);
	setup();
}
