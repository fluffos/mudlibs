// wujiang.c 武将

inherit NPC;
// inherit F_SKILL;
string ask_me();
void create()
{
	set_name("雄武营营官", ({ "wu jiang", "wu", "jiang" }));
	set("gender", "男性");
	set("age", random(10) + 30);
	set("str", 25);
	set("dex", 16);
	set("long", "他是雄武营的长官。\n");
	set("combat_exp", 75000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	set_skill("unarmed", 60);
	set_skill("force", 60);
	set_skill("halberd", 60);
	set_skill("lujia-ji", 60);
	set_skill("dodge", 60);
	set_skill("parry", 60);

	map_skill("halberd", "gehu-ji");
	map_skill("parry", "gehu-ji");

	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);
	set("inquiry", ([
			"兵书" : (: ask_me:),
			"book" : (: ask_me:),
	]));
	setup();
	carry_object("/clone/weapon/fangtianji")->wield();
	carry_object(__DIR__"obj/tiejia")->wear();
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

string ask_me()
{
	object ob=this_object(),me=this_player();
	if (me->is_busy())
	{
		return "你正忙着呢。\n";
	}
	if (me->query_temp("allow_scoop_sunzizhu"))
	{
		command("hmm");
		return "我不是告诉过你了吗？\n";
	}
	message_vision("$N向$n打听『孙子注』的下落。\n",me,ob);
	if (present("sunzi zhu",me))
	{
		command("say 不是在你身上吗？");
		return "";
	}
	if (me->query("class")!="officer"&&!me->query("song/pro")&&query("answered"))
	{
		command("say 我刚刚告诉了一个叫"+query("answer")+"的人，『孙子注』可能被他取走了。\n");
		return "";
	}
	command("whisper "+me->query("id")+" 『孙子注』就藏在雄武营对面的城隍庙，你只要去挖(scoop)就一定能找到的。\n");
	me->set_temp("allow_scoop_sunzizhu",1);
	set("answered",me->query("name"));
	return "";
}