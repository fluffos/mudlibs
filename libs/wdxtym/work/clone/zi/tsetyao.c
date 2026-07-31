
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
	set_name(HIR "四维药测试" NOR, ({ " siyaoyao"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "转世玩家可以服用，五分之一的概率可以触发彩蛋奖励，高转玩家血赚不亏\n");
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

	
	
		tell_object(me, "欧皇总是能得到更多，四维都增涨了\n");
	      //me->add("gift/unknowdan_fail", 1);
		me->add("str",5)+(me->query("zhuanshi")*2/3);//臂力
		me->add("int",5)+(me->query("zhuanshi")*2/3);//悟性
		me->add("dex",5)+(me->query("zhuanshi")*2/3);//身法
		me->add("con",5)+(me->query("zhuanshi")*2/3);//根骨
		
	
	
	

	add_amount(-1);
      return 1;
}


