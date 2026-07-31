
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
	set_name("tap好评礼包", ({"t gift"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一个好评的礼包！\n");
		set("base_unit", "个");
		set("base_weight", 1);
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
	int i;
	mapping gifts;
	string *list;
	object obj;
//    5个九转，5个天香，1个福寿膏，1个千年灵芝，10本无量经书
	gifts = ([
		"/clone/aaa/vip2/dan_jiuzhuan":10,			//九转
		"/clone/aaa/vip2/tianxiang":13,			//天香
		"/clone/aaa/vip2/fushougao":3,			//福寿膏
		"/clone/aaa/vip2/lingzhi":3,			//千年灵芝
	"/clone/aaa/vip2/book_wuliang":50,			//无量经书
		//"/clone/shizhe/dan_yuanbao":1,			//无量经书
		"/clone/shizhe/yuebing1":1,	
	//	"/clone/shizhe/hua":1,
	"/clone/aaa/weapon/yuanbao2":3,
	//	"/clone/mengzi":1,
	]);

	list = keys(gifts);

	if (me->is_busy())
		return notify_fail("你正忙着呢。\n");

	if (me->is_fighting())
		return notify_fail("战斗中，不能使用"+ name() +"。\n");

	message_vision("$N打开了一" + query("base_unit") + name() + "。\n", me);
	me->add("vip_box_times",1);
	log_ufile(me,"vipbox","第"+me->query("vip_box_times")+"次打开了"+this_object()->short()+"。\n");
	for(i=0;i<sizeof(list);i++)
	{
		obj = new(list[i]);
		if(obj->query_amount())
			obj->set_amount(gifts[list[i]]);
		tell_object(me,"你发现了"+obj->short()+"。\n");
		obj->move(me);
	}
	add_amount(-1);

	return 1;

}
