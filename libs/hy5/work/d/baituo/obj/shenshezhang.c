//shezhang.c
#include <ansi.h>
#include <weapon.h>
inherit STAFF;

void create()
{
	set_name(HIR"神蛇杖"NOR, ({ "sheng shezhang", "shengzhang" }));
	set_weight(2000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "根");
		set("long", "这是一根神蛇杖, 杖头二条小蛇, 红舌伸缩, 十分诡异。\n");
set("no_give",1);
		set("treasure",1);
                set("weapon_prop/dodge", 2);
                set("weapon_prop/parry", 3);
		set("value", 100);
		set("material", "leather");
		set("wield_msg", "$N「唰」的一声提起一根$n握在手中。\n");
		set("unwield_msg", "$N将手中的$n收回背后。\n");
	}
	init_staff(500);
	setup();
}
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 3);
        return 0;
}
