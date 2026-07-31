// yangcan popo
// by augx@sj  10/9/2001

// Modified by mxzhao 2004/03/06 
// caiji => nongsang
// delete /d/zhiye/obj/fangsuo

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("养蚕婆婆",({ "yangcan popo", "popo" }) );
	set("gender", "女性" );
	set("age", 62);
	set("long", 
"这是位满脸皱纹的老婆婆，一生都在种棉养蚕。
现在老了就卖些工具，教教年轻人过活。\n");

	set("str", 25);
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
	set_skill("nongsang", 70);

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
	set("no_ansuan",1);

	set("chat_chance", 5);
 	set("chat_msg", ({
 		"养蚕婆婆说道：“有人要买剪刀和纺梭吗？”\n",
 		"养蚕婆婆说道：“我的农桑技术最好了，谁也比不过。”\n",
 	}) );

	set("vendor_goods", ({
		//(["name":"/d/zhiye/obj/fangsuo","number":20]),
		(["name":"/d/zhiye/obj/jiandao","number":20]),
		(["name":"/d/zhiye/obj/tieqiao","number":20]),
		(["name":"/d/zhiye/obj/liandao","number":20]),
		(["name":"/d/zhiye/obj/saoba"  ,"number":20]),
		(["name":"/d/zhiye/obj/zhongzi1","number":50]),
		(["name":"/d/zhiye/obj/zhongzi2","number":50]),
		(["name":"/d/zhiye/obj/zhongzi3","number":50]),
		(["name":"/d/zhiye/obj/zhongzi4","number":50]),
		(["name":"/d/zhiye/obj/zhongzi5","number":50]),
		(["name":"/d/zhiye/obj/zhongzi6","number":50]),
		(["name":"/d/zhiye/obj/zhongzi7","number":50]),
		(["name":"/d/zhiye/obj/zhongzi8","number":50]),
		(["name":"/d/zhiye/obj/zhongzi9","number":50]),
	}));
		
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/jiandao")->wield();
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
}

int prevent_learn(object me, string skill)
{
	if (skill == "nongsang") return 0;
	return 1;
}

int is_apprentice_of(object me)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 100, level = ob->query_skill("nongsang", 1);
	
	if (level > 9) money = 150;
	if (level > 19) money = 300;
	if (level > 39) money = 500;
	if (level > 59) money = 1000;
	if (level > 50) return 0;
	
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"你现在的学费是每次"+MONEY_D->money_str(money)+"。你的钱不够！\n" ); return 0;
	}
	return 1;
}
