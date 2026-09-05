#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
    set_name(HIW"仿倚天剑"NOR, ({ "fang yitianjian", "jian", "sword" }));
	set_weight(2000);
    set("value", 10000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "柄");
        set("long", HIW "这是一把仿制的倚天剑，虽比不上真品，但也算是把锋利的好剑！\n" NOR);
		set("material", "steel");
	}
    init_sword(120);
	setup();
}

