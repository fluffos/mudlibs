
#include <ansi.h>

inherit COMBINED_ITEM;

string query_autoload() { return query_amount() + ""; }

void autoload(string param)
{
	int amt;

	if (sscanf(param, "%d", amt) == 1)
		set_amount(amt);
}

void setup()
{
	set_amount(1);
	::setup();
}

void create()
{
	set_name(WHT"五仁月饼"NOR, ({"yuebing1"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个大大的五仁月饼。\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 10);
        set("no_put", 1);
        set("no_get", 1);
        set("no_give", 1);
        set("no_drop", 1);
        set("no_sell", 1);
        set("no_steal", 1);
        set("no_beg", 1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
    int num1,num2,num3,num4;

    if (me->is_busy())
            return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

    num1=5000+random(5000);
    me->add("combat_exp",num1);
    num2=5000+random(5000);
    me->add("potential",num2);
    num3=5000+random(5000);
    me->add("experience",num3);
    num4=360+random(360);
    me->apply_condition("db_exp", num4+me->query_condition("db_exp"));

	message_vision(HIY"$N把一" + query("unit") + name() + HIY+"放入嘴里，细细咀嚼品尝，顷刻间露出满足的神情，似乎从来没有吃过如此美味。"NOR"\n", me);
	write(YEL"恭喜您：获得了"+num1+"点修为。"NOR"\n");
	write(YEL"恭喜您：获得了"+num2+"点潜能。"NOR"\n");
	write(YEL"恭喜您：获得了"+num3+"点实战体会。"NOR"\n");
	write(YEL"恭喜您：获得了"+num4/6+"分钟双倍时间。"NOR"\n");
	add_amount(-1);
	return 1;

}

