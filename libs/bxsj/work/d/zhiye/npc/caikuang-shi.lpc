// caikuang shifu  采矿师傅
// by augx@sj  9/7/2001

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("采矿师傅",({ "caikuang shifu", "shifu" }) );
	set("gender", "男性" );
	set("age", 56);
	set("long", 
"这是位饱经风霜的老采矿工人，现在老了，不能去采矿了，
只能靠卖些采矿工具，教年轻的工人一些初步的采矿知识过活。\n");

	set("str", 55);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	set("no_get", 1);

	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("literate", 150);
	set_skill("caikuang", 70);
	
	set("max_qi", 39999);
	set("max_neili", 49999);
	set("max_jing", 29999);
	set("eff_jingli", 29999);
	
	set_temp("apply/dodge",288);
	set_temp("apply/force",288);
	set_temp("apply/attack",288);
	set_temp("apply/damage",233);
	set_temp("apply/armor",288);
	
	set("unique",1);
	
	set("chat_chance", 5);
 	set("chat_msg", ({
 		"采矿师傅说道：“有人要买采矿打铁工具吗？”\n",
 		"采矿师傅说道：“谁救济我一下啊，我可以教他采矿技术。”\n",
 	}) );
	
	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/tieqiao","number":15]),
		(["name":"/d/zhiye/obj/tiechui","number":15]),
	}));
	
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/tieqiao")->wield();
	add_money("coin",99);
}

void kill_ob(object ob)
{
	object me = this_object();
	command("!!!");
	command("say 我只是一个可怜的老矿工，为什么要杀我呢？");
	me->remove_enemy(ob);
	ob->remove_killer(me);
	return;
}

int accept_fight(object ob)
{
	command("say 我只是一个可怜的老矿工，为什么要杀我呢？");
	return 0;
}

void init()
{
	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

int prevent_learn(object ob, string skill)
{
	if (skill == "caikuang")
		return 0;
	return 1;
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 100, level = ob->query_skill("caikuang", 1);
		
	if (level > 9) money = 250;
	if (level > 19) money = 500;
	if (level > 29) money = 1000;
	if (level > 49) money = 2000;
	if (level > 50) return 0;//实习结束了 
	
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"你现在的学费是每次"+MONEY_D->money_str(money)+"。你的钱不够！\n" ); return 0;
	}
	return 1;
}
