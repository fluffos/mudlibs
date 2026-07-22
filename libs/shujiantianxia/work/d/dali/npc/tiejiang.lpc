//  /d/dali/npc/dasao.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("打铁匠", ({ "Datie jiang", "jiang" }));
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 45);
	set("long","这位大汉光着上身,由于长年打铁,肌肉很是发达。\n");
	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_temp("apply/damage", 15);
        set("unique", 1);

	set("combat_exp", 40000);
	set("attitude", "friendly");

	set("inquiry", ([
		"工作"		: "我这里可没什么活可以干。",
		"job"		: "我这里可没什么活可以干。",
		"寻找矿石"	: "我这里可没什么活可以干。",
		"放弃"		: "嗯？你要放弃什么啊？",
		"abandon"	: "嗯？你要放弃什么啊？",
	]));

	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/kuangshi1","number":150]),
		(["name":"/d/zhiye/obj/kuangshi2","number":150]),
		(["name":"/d/zhiye/obj/kuangshi3","number":150]),
		(["name":"/d/zhiye/obj/kuangshi4","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi1-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi2-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi3-2","number":150]),
		//(["name":"/d/zhiye/obj/kuangshi4-2","number":150]),
        }));
	
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say 我是一个老实的铁匠，为什么要杀我呢？");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say 我是一个老实的铁匠，为什么要杀我呢？");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	//add_action("do_sell", "sell");
}

int query_goods_value(string goods, int number)
{
	object me = this_player();
	int value, trade_level;
	int cur;

	value = ((object)goods)->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (115 - trade_level) / 100;

	cur = query_temp("vendor_goods/"+goods);
	if( cur != number )
		value += value/6 * cur/number;

	return value;
}

int query_goods_value2(object goods)
{
	object me = this_player();
	int value, trade_level;

	value = goods->query("value");
	trade_level = me->query_skill("trade", 1) / 10;
	if (trade_level > 15) trade_level = 15;
	value = value * (85 + trade_level) / 100;

	return value;
}
/*
int do_sell(string arg)
{
	object ob;
	object me = this_player();
	int value, improve;

	if (!living(this_object()))
		return notify_fail("还是等对方醒来再说吧。\n");

	if (me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if (!arg || !(ob = present(arg, me)))
		return notify_fail("你要卖什么？\n");

	if (query_temp("busy"))
		return notify_fail("哟，抱歉啊，我这儿正忙着呢……您请稍候。\n");

	if ( !(int)ob->query("kuangshi") && !(int)ob->query("kuangcai") )
		return notify_fail("我只收购矿石，和用矿石打出来的成品。\n");

	value = query_goods_value2(ob);
	message_vision("$N以"+MONEY_D->price_str(value)+"的价格卖掉了一"+ob->query("unit")+ob->name() + "给$n。\n", me, this_object());
	destruct(ob);
	MONEY_D->pay_player(me, value);
	improve = 40 - me->query("pur");
	me->improve_skill("trade", improve / 2 + random(improve));
	set_temp("busy", 1);
	call_out("delete_temp", 1, "busy");

	return 1;
}
*/