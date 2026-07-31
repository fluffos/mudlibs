
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
	set_name(HIR "转世清除丹" NOR, ({"buchangyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "五分之一概率触发彩蛋，转世次数必减1！\n");
		set("unit", "颗");
		set("base_unit", "颗");
		set("base_weight", 10);
		set("base_value", 10000);
		set("tianji1", 150);
        set("no_sell", 1);
		set("give",1);
        set("drop",1);
        set("get",1); 
		set("suit_point", 300);
		set("only_do_effect", 1);
	}
	setup();
}

int do_effect(object me)
{
	message_vision("$N一仰脖，吞下了一" + query("unit") + name() + "。\n", me);

	if (me->query("zhuanshi") <= 0)
	{
		message_vision("当我不知道你没转世么？。\n", me);
		tell_object(me, "这就没收你的药。\n");
	} else
				if (me->query("zhuanshi") <= 30)
	{
		message_vision("恭喜你成功减少转世次数！\n", me);
		tell_object(me, "吃下丹药啦！\n");
            me->add("zhuanshi",-1);
	} else
	if (random(5) ==1 /* && !me->query("special_skill/lucky") */)
	{
		tell_object(me, "五分之一概率遇到这个小彩蛋，欧皇总是能得到更多，四维都增涨了\n");
	      //me->add("gift/unknowdan_fail", 1);
		me->add("str",1)+(me->query("zhuanshi")*2);//臂力
		me->add("int",1)+(me->query("zhuanshi")*2);//悟性
		me->add("dex",1)+(me->query("zhuanshi")*2);//身法
		me->add("con",1)+(me->query("zhuanshi")*2);//根骨
		
	} else
	{
		tell_object(me, HIM "给之前转世的人的补偿。"NOR"\n");
		me->set("gift/shenliwan",0);//删除臂力药次数
		me->set("gift/xiandan",0);//删除悟性药次数
		me->set("gift/unknowdan",0);//删除身法药次数
		me->set("gift/xisuidan",0);//删除根骨药次数
		write("\n "+HIR+"恭喜你："+NOR+HIG+"重置吃药次数成功"NOR"\n");
	
	}

	add_amount(-1);
      return 1;
}


