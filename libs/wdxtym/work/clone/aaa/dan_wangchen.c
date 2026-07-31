
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
	set_name(HIW"忘尘丹"NOR, ({"wangchen dan"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗神奇的药丸，据说可以忘掉一部分记忆。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 10);
            set("no_sell", 1);
            set("no_shop", 1);
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

      if (me->query("combat_exp")<200000)
                return notify_fail("你目前的修为太低，无需忘记。\n");
      else {
                me->add("combat_exp",-100000);

                message_vision("$N小心服用了一" + query("unit") + name() + "，似乎丢掉了什么重要的东西，一时又想不起来到底是什么。\n", me);
	          //write(YEL"恭喜您：消除了"+var+"点戾气。"NOR"\n");

	          add_amount(-1);
                return 1;
            }

}
