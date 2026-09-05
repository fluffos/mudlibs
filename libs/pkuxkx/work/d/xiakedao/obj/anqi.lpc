// 暗器
// by aiai

#include <weapon.h>

inherit THROWING;
#include <ansi.h>
void create()
{
	set_name( HIY"柳叶镖"NOR , ({ "liuye biao", "biao" }) );
	set_weight(50);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long","这是一把柳叶飞镖，从形态上看是专为女子设计的。\n");
		set("unit", "些");
		set("value", 20);
		set("base_weight", 50);
		set("base_unit", "枚");
	}
	set_amount(5);
	init_throwing(10);
	setup();
}

mixed hit_ob(object me, object victim, int damage_bonus)
{
	if ( ! userp(me) )
	{
		victim->add_qi(-100);
		message_vision(HIG"$N转动腰肢，抖手一镖，$n不觉看得痴了。\n"NOR,me,victim);
		message_vision(HIR"$N一个不慎被飞镖射中，顿时鲜血淋漓。！\n"NOR, victim);
	}
	else{
		message_vision(HIB"$N似乎不太会用柳叶飞镖。\n"NOR,me);
	}
}

