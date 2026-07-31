
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
	set_name("福袋", ({"newyear gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "新年礼物，里面装满了武动仙途对大家的新年祝福！\n");
		set("unit", "个");
		set("base_unit", "个");
		set("base_weight", 10);
		set("base_value", 1000);
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
	string *ls1,*ls2;
	object ob;
	
	ls1 = ({
		"/clone/newyear/2",
		"/clone/newyear/0",
		"/clone/newyear/1",
		"/clone/newyear/8",
		"/clone/newyear/xin",
		"/clone/newyear/chun",
		"/clone/newyear/kuai",
		"/clone/newyear/le",
	});

	ls2 = ({
		"/clone/newyear/gou",
		"/clone/newyear/nian",
		"/clone/newyear/xing",
		"/clone/newyear/da",
		"/clone/newyear/yun",
	});

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("正在战斗中，不能使用"+ name() +"。\n");

	num1=1000+random(1000);
	me->add("combat_exp",num1);
	num2=1000+random(1000);
	me->add("potential",num2);
	num3=1000+random(1000);
	me->add("experience",num3);

	message_vision("$N打开了一" + query("unit") + name() + "。\n", me);
	write(YEL"恭喜您：获得了"+num1+"点修为。"NOR"\n");
	write(YEL"恭喜您：获得了"+num2+"点潜能。"NOR"\n");
	write(YEL"恭喜您：获得了"+num3+"点实战体会。"NOR"\n");
	
	if(!random(3))
	{
		ob = new(ls1[random(sizeof(ls1))]);
		write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
		ob->move(me);
	}
	if(!random(10))
	{
		ob = new(ls2[random(sizeof(ls2))]);
		write(YEL"恭喜您：获得了"+ob->short()+"。"NOR"\n");
		ob->move(me);
	}
	add_amount(-1);
	me->save();
	return 1;

}
