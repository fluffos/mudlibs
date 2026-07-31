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
	set_name(HIG"葡萄"NOR, ({"putao"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("value", 100);
		set("yuanbao", 10);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("no_get",1);
		set("unit", "串");
		set("base_unit", "串");
		set("base_weight", 1);
		set("base_value", 100);
		set("long","这是一串由吐蕃传入中原的"HIG"葡萄"NOR"，吃下它会发生奇怪的事情！(潜能+2000)\n");
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	me->add("potential",2000);
	write(YEL"你吃下一串"HIG"葡萄"YEL"发现自己的潜能大增!"NOR"\n");

        if (random(1000)==1) {
            me->add("per",1);
            message_vision(HIW"只见$N身上发出一道耀眼的白光，似乎发生了什么神奇的事情。"NOR"\n", me);
            write(HIM"恭喜：你的先天容貌提升了!"NOR"\n");
            }
	add_amount(-1);
	return 1;
}