#include <weapon.h>
#include <ansi.h>

inherit STAFF;

void create()
{
	set_name(HIG"蛇杖" NOR, ({ "she zhang", "shezhang", "zhang"}));
	set_weight(15000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "一根顶部有条毒蛇的蛇杖。\n");
		set("value", 5000);
		set("material", "steel");
		set("poisoned", "snake_poison");
                set("poison_number", 100);
	}
	init_staff(30);
	setup();
}


