// design by 发现号(find) . all right reserved.

// m_boss.c

inherit NPC;

string ask_me(object who);

string *biaozi = ({
"hong_xiu",
"lian_yu",
"wan_xiang",
"xiang_yu"
});

void create()
{
	set_name("老鸨", ({ "m_boss" }) );
	set("gender", "女性" );
	set("age", 35);
	set("str", 20);
	set("per", 28);
	set("long", @LONG
一位浓妆艳抹的半老徐娘，但风韵尤存，全身上下珠
光宝气，看样子他就是这里的老板娘了。
LONG
);
	set("combat_exp", 100);
	set("attitude", "friendly");

	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);

	set("inquiry", ([
		"畅春园": "这里就是畅春园呀！我们这的四朵金花远近闻名。",
		"花酒" : (: ask_me :),
	]) );

	setup();
	
	carry_object(__DIR__"obj/xiu_shoes")->wear();
	carry_object(__DIR__"obj/pink_cloth")->wear();
}

void init()
{	
	object who = this_player();

	::init();
	if( interactive(who) && !is_fighting() && !who->query_temp("order") ) {
		remove_call_out("greeting");
		call_out("greeting", 1, who);
	}
	add_action("ask_order","order");
}

void greeting(object who)
{
	if( !who || environment(who) != environment() ) return;
	if(who->query("gender") == "男性" && !who->query_temp("jiyuan/order"))
	{
		if(1==2)
			message_vision( "老鸨冲着$N微笑道：我们这的四朵金花远近闻名，"+
			"请爷天黑了来吧，一定让您好好爽爽。\n",who);
		else
			message_vision( "老鸨冲着$N微笑道：这位"+RANK_D->query_respect(who)+
			"要不要摆一桌花酒，我把孩子们叫出来陪您？\n",who);
	}
	if(who->query("gender") == "女性")
		message_vision( "老鸨奇怪的望着$N说道：这位"+RANK_D->query_respect(who)+
			"跑我们这种地方来做什么？\n",who);
}

string ask_me(object who)
{
	object me = this_player();
	if(me->query("gender") == "女性")
		return "你也来摆花酒,我们可没有小生陪您。\n";
	else
		return "爷动动小指头我们就发达了，门口的牌子上写着，爷仔细看看。";
}

int ask_order(string arg)
{
	object mgold,me = this_player();

	if(1==2)
		return notify_fail("姑娘们正休息呢，请晚上天黑了再来吧。\n");

	if(query_temp("cant_order")) return 0;
	if( me->query("gender") == "女性")
		return notify_fail("你也来摆花酒,我们可没有小生陪您。\n");
	if(!arg)
		return notify_fail("您要摆哪种花酒？\n");
	if(arg != "putong" && arg != "yinwei" && arg != "jinwei")
		return notify_fail("您要摆哪种花酒？\n");
	if(!mgold = present("gold_money", me))
		return notify_fail("没钱少来我们这！\n");
	if(query_temp("have_full"))
		return notify_fail("楼上已经被人包了，爷等一会儿吧。\n");
	if(me->query_temp("on_rided"))
		return notify_fail("爷怎么骑着坐骑到我们这来玩，我们的姑娘干什么呀。\n");

	if(arg == "putong")
	{
		if((int)mgold->query_amount() < 5)
			return notify_fail("钱都不够摆什么花酒！\n");
		command("say 谢谢爷！来了就是客，爷请上楼，我叫个姑娘陪您。");
		set_temp("cant_order",1);
		mgold->set_amount((int)mgold->query_amount() - 5);
		me->set_temp("jiyuan/order",1);
		command("go up");
		call_out("order_putong",3,me);
		return 1;
	}

	else if(arg == "yinwei")
	{
		if((int)mgold->query_amount() < 10)
			return notify_fail("钱都不够摆什么花酒！\n");
		set_temp("cant_order",1);
		command("say 爷真是大财主！楼上请，我叫几个姑娘好好陪您。");
		mgold->set_amount((int)mgold->query_amount() - 10);
		me->set_temp("jiyuan/order",1);
		command("go up");
		call_out("order_yinwei",3,me);
		return 1;
	}

	else if(arg == "jinwei")
	{
		if((int)mgold->query_amount() < 20)
			return notify_fail("钱都不够摆什么花酒！\n");
		set_temp("cant_order",1);
		command("say 爷莫不是财神托世！爷快请上楼，我叫姑娘们都来陪您。");
		mgold->set_amount((int)mgold->query_amount() - 20);
		me->set_temp("jiyuan/order",1);
		command("go up");
		call_out("order_jinwei",3,me);
		return 1;
	}
}

void order_putong(object me)
{
	object ji;
	if(environment(me) != environment())
		{
		if(query_temp("have_wait")) {
			delete_temp("cant_order");
			delete_temp("have_wait");
			me->delete_temp("jiyuan/order");
			//command("down");
			return;
			}
		tell_object(environment(me),"老鸨喊着："+me->name()+"大爷请上二楼。\n");
		set_temp("have_wait",1);
		call_out("order_putong",3,me);
		}
	else {
	ji = new(__DIR__+biaozi[random(4)]);
	message_vision("\n老鸨喊道："+ji->name()+"来接客啦！\n",this_object());
	ji->move(environment());
	tell_object(environment(),ji->name()+"走了出来。\n\n");
	command("tell "+(string)me->query("id")+" 爷好好玩吧，她今天就是您的了。");
	delete_temp("cant_order");
	delete_temp("have_wait");
	//command("down");
	set_temp("have_full",1);
	return;
	}
}

void order_yinwei(object me)
{
	object ji_one,ji_two;
	int i;

	if(environment(me) != environment())
	{
		if(query_temp("have_wait"))
			{
			delete_temp("cant_order");
			delete_temp("have_wait");
			me->delete_temp("jiyuan/order");
			//command("down");
			return;
			}

		tell_object(environment(me),"老鸨喊着："+me->name()+"大爷请上二楼。\n");
		set_temp("have_wait",1);
		call_out("order_yinwei",3,me);
	}

	else
	{
	i = random(4);
	ji_one = new(__DIR__+biaozi[i]);
	if(i == 3 ) i = 0;
	else i += 1;
	ji_two = new(__DIR__+biaozi[i]);
	message_vision("\n老鸨喊道：姑娘们来接客啦！\n\n",this_object());

	ji_one->move(environment());
	tell_object(environment(),ji_one->name()+"走了出来。\n");
	ji_two->move(environment());
	tell_object(environment(),ji_two->name()+"走了出来。\n\n");

	command("tell "+(string)me->query("id")+" 爷好好玩吧，她们今天就是您的了。");
	delete_temp("cant_order");
	delete_temp("have_wait");
	//command("down");
	set_temp("have_full",1);
	return;
	}
}

void order_jinwei(object me)
{
	object ji_o,ji_t,ji_s,ji_f;

	if(environment(me) != environment())
	{
		if(query_temp("have_wait")) {
			delete_temp("cant_order");
			delete_temp("have_wait");
			me->delete_temp("jiyuan/order");
			//command("down");
			return;
			}
		tell_object(environment(me),"老鸨喊着："+me->name()+"大爷请上二楼。\n");
		set_temp("have_wait",1);
		call_out("order_jinwei",3,me);
	}
	else
	{

	ji_o = new(__DIR__+biaozi[0]);
	ji_t = new(__DIR__+biaozi[1]);
	ji_s = new(__DIR__+biaozi[2]);
	ji_f = new(__DIR__+biaozi[3]);

	message_vision("\n老鸨喊道：姑娘们都快来接财神爷啦！\n\n",this_object());

	ji_o->move(environment());
	tell_object(environment(),ji_o->name()+"走了出来。\n");
	ji_t->move(environment());
	tell_object(environment(),ji_t->name()+"走了出来。\n");
	ji_s->move(environment());
	tell_object(environment(),ji_s->name()+"走了出来。\n");
	ji_f->move(environment());
	tell_object(environment(),ji_f->name()+"走了出来。\n\n");

	command("tell "+(string)me->query("id")+" 爷好好玩吧，她们今天全是您的了。");
	delete_temp("cant_order");
	delete_temp("have_wait");
	//command("down");
	set_temp("have_full",1);
	return;
	}
}