// zhangty.c

inherit NPC;

void create()
{
	set_name("张天有", ({ "zhang tianyou" }) );

	set("title","流氓狗少");

	set("gender", "男性" );
	set("age", 23);

	set("attitude","peaceful");

	set("long", "这位是大同张家的小少爷，平时无恶不作。。\n");

	set("combat_exp", 20000);

	set("str", 30);

	set("kee",900);
	set("force", 200);
	set("max_force", 200);
	set("force_factor", 5);

	set_skill("unarmed",40);
	set_skill("dodge",30);
	set_skill("parry",30);

	set("chat_chance_combat",30);
	set("chat_msg_combat",({
	"\n张天有喊道：干什么和我过不去！我怎么你了！\n\n",
	"\n张天有喊道：你要干什么！我除了调戏妇女欺负要饭的就没干过坏事啦！\n\n",
	"\n张天有喊道：干什么和我过不去！我爹有的是钱！\n\n",
	"\n张天有喊道：到底怎么啦！我把你孩子扔井里去啦！\n\n",
 }));

	setup();
	add_money("silver",2);
	carry_object("/clone/misc/cloth")->wear();
}

void die()
{
	object killer = query_temp("last_damage_from"),zhu;


	if(objectp(killer)
	&& killer->query("quest/shaolin_quest/name") == "紫灵芝")
	{
		zhu = new(__DIR__"obj/biduzhu");
		zhu->move(this_object());
	}

	::die();
}
