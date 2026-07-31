
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
	set_name(HIG "神力丸" NOR, ({ "shenli wan", "wan"}) );
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一颗圆圆的神力丸，据说吃了可以增强膂力。\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 100);
            set("no_sell", 1);
		set("suit_point", 300);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一" + query("unit") + name() + "。\n", me);

	if (me->query("gift/shenliwan") >= 5)
	{
		message_vision("$N眨眨眼。\n", me);
		tell_object(me, "你觉得这药没啥味道，还不如花生好吃。\n");
	} else
	if (random(10) >3 && !me->query("special_skill/lucky"))
	{
		tell_object(me, "不过你觉得好像没什么作用。\n");
	} else
	{
		tell_object(me, HIR "你觉得双臂几乎爆裂，充满了力量。"NOR"\n");
		me->add("str", 1);
	      me->add("gift/shenliwan", 1);
		write("\n "+HIR+"恭喜你："+HIG+"服用神力丸成功，《先天臂力》增加了！！！"NOR"\n");
	}

	add_amount(-1);
      return 1;
}



