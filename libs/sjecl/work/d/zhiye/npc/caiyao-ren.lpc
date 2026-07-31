// caiyao ren
// by augx@sj  3/4/2002

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("采药人",({ "caiyao ren", "ren" }) );
	set("gender", "男性" );
	set("age", 56);
	set("long", "这是位满脸风霜的老采药人，一生都以采药为生。\n");

	set("str", 25);
	set("dex", 55);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);
	set("move_seller", 1);
	set("shen", 100);
	set("attitude", "peaceful");
	set("combat_exp", 1000000);
	
	set_skill("dodge", 200);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("unarmed", 200);
	set_skill("literate", 150);
	set_skill("caiyao", 70);
	
	set("max_qi", 9999);
	set("max_neili", 9999);
	set("max_jing", 9999);
	set("eff_jingli", 9999);
	
	set_temp("apply/dodge",288);
	set_temp("apply/force",288);
	set_temp("apply/attack",288);
	set_temp("apply/damage",233);
	set_temp("apply/armor",288);
	
	set("unique",1);
	
	set("chat_chance", 3);
 	set("chat_msg", ({
 		"采药人说道：“有人要买采药工具吗？”\n",
 		"采药人说道：“我的采药技术最好了，谁也比不过。”\n",
 	}) );
	
	set("vendor_goods", ({
		(["name":"/d/zhiye/obj/yaochui","number":20]),
		(["name":"/d/zhiye/obj/yaochu", "number":20]),
	}));
	
	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}));

	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(__DIR__"../obj/yaochu")->wield();
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

int prevent_learn(object ob, string skill)
{
	if (skill == "caiyao") return 0;
	return 1;
}

int is_apprentice_of(object ob)
{
	return 1;
}

int recognize_apprentice(object ob)
{
	int money = 100, level = ob->query_skill("caiyao", 1);
	
	if (level > 9) money = 150;
	if (level > 19) money = 300;
	if (level > 39) money = 500;
	if (level > 59) money = 1000;
	
	switch (MONEY_D->player_pay(ob, money)) {
		case 0:
		case 2: tell_object(ob,"你现在的学费是每次"+MONEY_D->money_str(money)+"。你的钱不够！\n" ); return 0;
	}
	return 1;
}
