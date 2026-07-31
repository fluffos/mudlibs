// puti-zi.c 菩提子

#include <ansi.h>

inherit ITEM;

void setup()
{
}

void create()
{
	set_name(HIG "菩提子" NOR, ({"puti zi", "zi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "颗");
		set("long", HIG "这是一颗晶莹如玉的菩提子，采自灵山佛祖座"
			    "前，珍稀无比，\n乃万年菩提树之实，功能化百劫"
			    "，渡千灾，与天地同寿。\n");
		set("value", 50);
           	 set("suit_point",200);
                set("only_do_effect", 1);
                set("mixture", ([
                        "herb" : ([ "tenghuang" : 2,
                                    "mahuang"   : 2,
                                    "xionghuang": 2,
                                    "duhuo"     : 2,
                                    "yanwo"     : 2,
                                    "xiongdan"  : 2,
                                    "lurong"    : 2,
                                    "shancha"   : 2,
                                    "renshen"   : 2,
                                    "xuelian"   : 2,
                                    "lingzhi"   : 2, ]),
                        "neili" : 400,
                        "jing"  : 60,
                        "time"  : 8,
                        "min_level" : 150,
                        "liandan-shu" : 300,
                ]));

	}
	setup();
}

int do_effect(object me)
{

	if ((int)me->query_condition("putizi_drug") > 0)
	{
		write("你觉得现在内息未定，经脉隐隐还能感到真气冲荡，不"
		      "敢贸然服食。\n");
		return 1;
	} else
	if (me->improve_neili(40 + random(40)))
	{
		me->set("neili", me->query("max_neili"));

		message_vision(HIY "$N" HIY "吃下一颗菩提子，顿然间只觉一股浩"
			       "荡无比的真气直冲顶门，连忙运功吸纳。"NOR"\n",
			       me);
		//me->apply_condition("putizi_drug", 10);
	} else
	{
		message_vision(HIY "$N" HIY "一仰脖，吞下了一颗菩提子。"NOR"\n",
			       me);
		tell_object(me, "你觉得没啥感觉，不如花生好吃。\n");
	}

	me->start_busy(random(5) + 5);
	destruct(this_object());
	return 1;

}
