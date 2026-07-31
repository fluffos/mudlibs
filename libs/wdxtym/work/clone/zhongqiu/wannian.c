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
	set_name(HIR"万年火灵芝"NOR, ({"huo lingzhi"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 10000);
		set("yuanbao", 200);
        set("no_sell",1);
		set("unit", "株");
		set("base_unit", "株");
		set("base_weight", 10);
				set("no_drop1", 1);

				set("no_drop", 1);
				set("no_sell", 1);
				set("no_give", 1);
				set("no_get", 1);
				set("no_steal", 1);
		set("base_value", 10000);
		set("long","这是一颗万年火灵芝，可以增加2000点内力上限。\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	object ob1;
	int times;

	times = time();


	me->add("max_neili", 2000);
	message_vision(YEL+me->query("name")+"服下一株"HIR"万年火灵芝"YEL"，顿觉内力大增！"NOR"\n",me);

	add_amount(-1);
	return 1;
}

