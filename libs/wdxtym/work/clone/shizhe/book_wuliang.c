
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
	set_name("无量经书", ({"kungfu book"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "记载了武学心得的一页残卷。\n");
		set("unit", "页");
		set("base_unit", "页");
		set("base_weight", 10);
		set("base_value", 10000);
		set("yuanbao", 7);
            set("no_sell",1);
            set("no_give",1);
            set("no_drop",1);
            set("no_get",1);
            set("no_put",1);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
      int exp2;

      if (me->is_busy())
                return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		    return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

      if ((me->query("experience")-me->query("learned_experience"))>50000)
                return notify_fail("你的实战体会已达到一个瓶颈，目前不适合阅读"+ name() +"。\n");
      else {
                exp2=1400+random(201);
                me->add("experience",exp2);

                message_vision("$N仔细研读了一" + query("unit") + name() + "，只觉一阵醍醐灌顶，顿时豁然开朗。\n", me);
	          write(YEL"恭喜您：获得了"+exp2+"点实战体会。"NOR"\n");

	          add_amount(-1);
                return 1;
            }

}
