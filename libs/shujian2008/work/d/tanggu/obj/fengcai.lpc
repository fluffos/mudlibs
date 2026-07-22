#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
        set_name(HIY"凤钗"NOR, ({ "fengcai", "cai" }));
        set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
                set("long", "这是一柄金灿灿的钗子，雕成了一只凤凰的样子。\n");
                set("value", 5000);
		set("material", "gold");
		set("female_only", 1);
		set("armor_prop/armor", 1);
	}
	setup();
}
