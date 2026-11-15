// sample master.c code

inherit NPC;
inherit F_MASTER;

void consider();
string ask_me();
int accept_object(object ob, object obj);

void create()
{
	set_name("简长老", ({"jian zhanglao", "jian", "zhanglao"}));
	set("title", "丐帮九袋长老");
	set("nickname", "执法长老");
	set("gender", "男性");
	set("no_get", 1);
	set("age", 50);
	set("long", 
		"简长老是丐邦的执法长老，代帮主执掌法刀以及青竹令等。"
		"他向来嫉恶如仇，弟子中有谁犯过，出手决不容情。\n");

	set("attitude", "peaceful");
	
	set("str", 27);
	set("int", 22);
	set("con", 24);
	set("dex", 20);

	set("qi", 900);
	set("max_qi", 900);
	set("jing", 100);
	set("max_jing", 100);
	set("neili", 1500);
	set("max_neili", 1500);
	set("jiali", 100);

	set("combat_exp", 880000);
	set("score", 20000);

	set_skill("force", 170);
	set_skill("jiaohua-neigong", 170);
	set_skill("unarmed", 165);
	set_skill("changquan", 165);
	set_skill("dodge", 150);
	set_skill("feiyan-zoubi", 150);
	set_skill("parry", 175);
	set_skill("staff", 150);
	set_skill("jiaohua-bangfa", 150);

	map_skill("force", "jiaohua-neigong");
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
	map_skill("dodge", "feiyan-zoubi");
	map_skill("staff", "jiaohua-bangfa");

	create_family("丐帮", 18, "九袋长老");

	set("inquiry", ([
		"青竹令" :     (: ask_me :)
	]));

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(: exert_function, "recover" :),
	}) );

	setup();

	carry_object("/clone/weapon/tiegun")->wield();
}

void init()
{
	object ob;
	mapping myfam;
	
	::init();
	if (interactive(ob = this_player()) && ! is_fighting())
	{
		myfam = (mapping)ob->query("family");
		if ((! myfam || myfam["family_name"] != "丐帮") &&
		    ! wizardp(ob))
		{
			remove_call_out("saying");
			call_out("saying", 1, ob);
		}
	}
}

void saying(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	message_vision("\n简长老看了$N一眼，冷冷地说到：“洪帮主他老人家说我不该"
	    "随意责打丐帮弟子，\n你又不属我丐帮，我打你总可以吧？”\n"
	    "说完右腿一抬，$N顺势应了一招青城派的「屁股向后，平沙落雁式」"
	    "－－叭叽\n\n", ob);
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (! ob || environment(ob) != environment())
		return;

	ob->move("/d/city/pomiao");
	message("vision","只听“嘭”地一声，紧接着" +  ob->query("name") +
		"从小门里飞了出来，屁股上有一个清楚的鞋印。\n",
		environment(ob), ob);
}

void attempt_apprentice(object ob)
{
	command("say 老夫不收徒弟，" + RANK_D->query_respect(ob) + "还是请回吧。");
}

string ask_me()
{
	mapping fam;
	object ob, me;
 
 

	me = this_player();

	if (is_busy() || is_fighting())
		return "你等一会儿，我正忙呢。\n";

	if (! (fam = me->query("family")) || fam["family_name"] != "丐帮")
		return RANK_D->query_respect(me) +
		"与本派素无来往，不知此话从何谈起？";

	if (me->query("combat_exp", 1) < 1000)
		return "哼，你就这点本事也好意思来要青竹令？";

	if (present("qingzhu ling", me))
		return "你身上不是已经有青竹令了吗？";

	ob = new(__DIR__"obj/qingzhu-ling");
	ob->move(me);
	message_vision("$N获得一面青竹令。\n",me);

	start_busy(3 + random(5));
	return "好吧，凭这面青竹令，你可自由向你的同门大师兄挑战。";
}

int accept_object(object ob, object obj)
{
	object me = this_object();

	if (ob->query_temp("have_cloth") && obj->query("id") == "po bu")
	{
		command("say 既然升袋，就当牢记帮规，为民除害！");
		message_vision("$N接过了破布，然后把它钉在$n的破衣服上，"
			       "俨然一个新口袋。\n", me, ob);
		ob->delete_temp("have_cloth");
		ob->set("title", ob->query_temp("newtitle"));
		ob->delete_temp("newtitle");
		if (ob->query("title") == "丐帮一袋弟子")
		{
			ob->add("combat_exp", 250);
			ob->add("potential", 250);
			ob->set("beggarlvl", 1);
		}
		if (ob->query("title") == "丐帮二袋弟子")
		{
			ob->add("combat_exp", 500);
			ob->add("potential", 500);
			ob->set("beggarlvl", 2);
		}
		if (ob->query("title") == "丐帮三袋弟子")
		{
			ob->add("combat_exp", 1000);
			ob->add("potential", 1000);
			ob->set("beggarlvl", 3);
		}
		if (ob->query("title") == "丐帮四袋弟子")
		{
			ob->add("combat_exp", 1500);
			ob->add("potential", 1500);
			ob->set("beggarlvl", 4);
		}
		if (ob->query("title") == "丐帮五袋弟子")
		{
			ob->add("combat_exp", 2000);
			ob->add("potential", 2000);
			ob->set("beggarlvl", 5);
		}
		if (ob->query("title") == "丐帮六袋弟子")
		{
			ob->add("combat_exp", 3000);
			ob->add("potential", 3000);
			ob->set("beggarlvl", 6);
		}
		if (ob->query("title") == "丐帮七袋弟子")
		{
			ob->add("combat_exp", 4000);
			ob->add("potential", 4000);
			ob->set("beggarlvl", 7);
		}
		if (ob->query("title") == "丐帮八袋弟子")
		{
			ob->add("combat_exp", 5000);
			ob->add("potential", 5000);
			ob->set("beggarlvl", 8);
		}
		if (ob->query("title") == "丐帮九袋长老")
		{
			ob->add("combat_exp", 10000);
			ob->add("potential", 10000);
			ob->set("beggarlvl", 9);
		}
		destruct(obj);
		return 1;
	}
}