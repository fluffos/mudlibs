
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
	set_name(HIB"听雨阁资格"NOR, ({"zige dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗神奇的药丸，据说可以获得听雨阁资格。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 100000000);
        set("no_sell", 1);
		set("only_do_effect", 1);
		set("end","/clone/tingyuge");
	}
	setup();
}

int do_effect(object me)
{
    int var;

    if (me->is_busy())
        return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");
	
	if (me->query("tingyvge"))
		return notify_fail("你还有一次资格呢。\n");


        me->add("tingyvge",1);
		me->set("lenque",1);

        message_vision("$N小心服用了一" + query("unit") + name() + "，获得了一次听雨阁的资格。\n", me);

	    add_amount(-1);
        return 1;
    

}
