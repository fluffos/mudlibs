// kongkong.c

inherit NPC;
inherit F_MASTER;
inherit F_UNIQUE;

void consider();

void create()
{
	seteuid(getuid());
	set_name("空空儿", ({ "kong kong","beggar","qi gai","kong" }) );
	set("title", "妙手神丐");
	set("gender", "男性" );
	set("age", 53);
	set("long", "一个满脸风霜之色的老乞丐。\n");
	set("attitude", "peaceful");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);
	set("kar", 100);

	set("qi", 2500);
	set("max_qi", 2500);
	set("jing", 1200);
	set("max_jing", 1200);
	set("neili", 4500);
	set("max_neili", 4500);
	set("jiali", 80);

	set("shen_type", 0);
	set("thief", 0);
	set("combat_exp", 550000);

	set_skill("force", 150);
	set_skill("unarmed", 100);
	set_skill("sword", 80);
	set_skill("dodge", 150);
	set_skill("parry", 150);
	set_skill("stealing", 190);
	set_skill("begging", 150);
	set_skill("checking", 150);
	set_skill("jiaohua-neigong", 150);
	set_skill("changquan", 100);
	set_skill("feiyan-zoubi", 150);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	map_skill("dodge", "feiyan-zoubi");

	create_family("丐帮", 19, "八袋长老");

	set("chat_chance", 2);
	set("chat_msg", ({
		"空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～\n",
		"空空儿懒洋洋地打了个哈欠。\n",
		"空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 \n",
		"空空儿说道: 好心的大爷哪～ 赏我要饭的几个铜板吧～\n",
		"空空儿懒洋洋地打了个哈欠。\n",
		"空空儿伸手捉住了身上的虱子，骂道: 老子身上没几两肉，全叫你们给咬糜了。 \n",
		(: random_move :)
	}) );

	set("chat_chance_combat", 120);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/clone/food/jitui");
	carry_object("/clone/food/jiudai");
	add_money("silver", 10);
}

void attempt_apprentice(object ob)
{
	if( ob->query("detach/丐帮") )
	{
		command("say 哈哈！想吃回头草？没门！");
		return 0;
	}

	if( ob->query("betrayer") )
	{
		command("say 我们丐帮虽然是叫花子，但是堂堂正正行路，不会收过判师的！");
		return 0;
	}

	if (ob->query("family/family_name") != "丐帮")
	{
		command("say 嘿！你既然已经有了名师指点，还来找我老叫花干什么？");
		return 0;
	}

	command("say 好吧，希望" + RANK_D->query_respect(ob) +
	"能好好学习本门武功，将来在江湖中闯出一番作为。");
	command("recruit " + ob->query("id"));
	if((string)ob->query("class") != "beggar")
		ob->set("class", "beggar");
}

int recognize_apprentice(object ob, string skill)
{
	if (ob->query("family/family_name") != "丐帮")
		return 0;

	if (skill != "stealing" && skill != "begging" &&
	    skill != "checking")
	{
		message_vision("$n凑上前去，可是$N左右看看，好像没有听见$n在说什么。\n",
			       this_object(), ob);
		return -1;
	}

	return 1;
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) ) {
		remove_call_out("stealing");
		call_out("stealing", 1, ob);
	}
}

void stealing(object ob)
{
	mapping fam; 
 
	if (! ob || environment(ob) != environment() ||
	    ((fam = ob->query("family")) && fam["family_name"] == "丐帮") ||
	    (int)ob->query_skill("taoism", 1) > 30 ||
	    ob->query_int() > 30)
		return;

	switch(random(5))
	{
		case 0:
		       command("hehe " + ob->query("id"));
		       command("beg coin from " + ob->query("id"));
		       command("buy jitui");
		       break;
		case 1:
		       command("grin " + ob->query("id"));
		       command("steal silver from " + ob->query("id"));			
		       command("eat jitui");
		       break;
		case 2:
		       command("hi " + ob->query("id"));
		       command("steal gold from " + ob->query("id"));			
		       command("drink jiudai");
		       break;
		case 3:
		       command("pat " + ob->query("id"));
		       command("beg jiudai from " + ob->query("id"));	
		       command("eat jitui");
		       break;
		case 4:
		       command("walkby " + ob->query("id"));
		       command("beg jitui from " + ob->query("id"));	
		       command("drink jiudai");
		       break;
	}
}


int accept_object(object me, object obj)
{
	if (obj->query("money_id") && obj->value() >= 1)
	{
		command("smile");
		command("say 多谢啦 ! 其实我还是有点钱的，这次"
			"只不过试试你罢了 !");
		return 1;
	} else
	{
		command("shake");
		command("say 这种东西鬼才要 ! 滚一边去 !");
		command("give " + obj->query("id") + " to " +
		me->query("id"));
	}

	return 1;
}

int accept_fight(object me)
{
	command("say " + RANK_D->query_respect(me) + "饶命！小的这就离开！\n");
	return 0;
}

void die()
{
 
	message_vision("$N倒在地上，挣扎了两下，死了。\n", this_object());
	destruct(this_object());
}
