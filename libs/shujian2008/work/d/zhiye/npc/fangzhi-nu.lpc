// fangzhi-nu
// by augx@sj  10/9/2001

// Modified by mxzhao 2004/03/06 
// delete bianzhi skill

#include <ansi.h>
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("纺织女",({ "fangzhi nu","nu" }) );
	set("gender", "女性" );
	set("age", 35);
	set("long","这是位纺织女工，从事纺织已经多年了，闲时也做些纺织品的买卖和教教年轻人。\n");

	set("str", 35);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);

	set_skill("dodge", 300);
	set_skill("force", 300);
	set_skill("parry", 300);
	set_skill("unarmed", 300);
	set_skill("literate", 150);
//	set_skill("bianzhi", 60);

	set("max_qi", 99999);
	set("max_neili", 99999);
	set("max_jing", 99999);
	set("max_jingli", 99999);
	set("eff_jingli", 99999);

	set_temp("apply/dodge",888);
	set_temp("apply/force",888);
	set_temp("apply/attack",888);
	set_temp("apply/damage",333);
	set_temp("apply/armor",888);

	set("chat_chance", 1);
 	set("chat_msg", ({
 		CYN"纺织女说道：「有人要买棉花吗？」\n"NOR,
 		//CYN"纺织女说道：「我的编织技术可是一流，要人要学吗？」\n"NOR,
 	}) );

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
	carry_object(__DIR__"../obj/fangsuo")->wield();
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

/*
int prevent_learn(object, string skill)
{
	if (skill == "bianzhi") return 0;
	return 1;
}
*/

int is_apprentice_of(object ob)
{
	return 0;
	//return 1;
}

/*
int recognize_apprentice(object ob)
{
	int money = 125, level = ob->query_skill("bianzhi", 1);

	if (level > 9) money = 250;
	if (level > 19) money = 500;
	if (level > 29) money = 1000;
	if (level > 49) money = 2000;

	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"你现在的学费是每次"+MONEY_D->money_str(money)+"。你的钱不够！\n" ); return 0;
	}
	return 1;
}
*/

////////////////////////////////////////////////////////////////////
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
