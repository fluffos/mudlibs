// women.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("阿香", ({ "a xiang", "xiang","women" }));
	set("title", "大理一枝花");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "女性");
        set("per",27);
        set("unique", 1);
	set("age", 25);
	set("long",
		"她是城里有名的大美人，\n"
		"她经常到这里来做自己喜欢的衣服。\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");

	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/buliao1","number":150]),
		(["name":"/d/zhiye/obj/buliao2","number":150]),
		(["name":"/d/zhiye/obj/buliao3","number":150]),
		(["name":"/d/zhiye/obj/buliao4","number":150]),
		//(["name":"/d/zhiye/obj/buliao1-2","number":150]),
		//(["name":"/d/zhiye/obj/buliao2-2","number":150]),
		//(["name":"/d/zhiye/obj/buliao3-2","number":150]),
		//(["name":"/d/zhiye/obj/buliao4-2","number":150]),
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	add_money("coin",99);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say 我和你无怨无仇，为何要害我！");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say 我和你无怨无仇，为何要害我！");
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

	if ( !(int)ob->query("buliao") && !(int)ob->query("bu") )
		return notify_fail("我只收购布料和布匹。\n");

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
