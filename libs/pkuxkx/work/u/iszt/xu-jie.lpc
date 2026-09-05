//npc: xu-jie
//iszt
inherit NPC;

string ask_yaoli();
string ask_yaoxing();

void create()
{
	set_name("虚劫", ({
		"xu jie",
		"xu",
		"jie",
	}));
	set("long",
		"他是一位身穿黄布袈裟的青年僧人。脸上稚气未脱，跟在道字辈\n"
		"禅师身后忙来忙去，似乎对药理药性略有研究。\n"
	);

	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 20);
	set("shen_type", 1);
	set("str", 20);
	set("int", 20);
	set("con", 25);
	set("dex", 15);
	set("max_qi", 350);
	set("max_jing", 200);
	set("neili", 300);
	set("max_neili", 300);
	set("jiali", 20);
	set("combat_exp", 30000);

	set_skill("force", 60);
	set_skill("yijin-jing", 30);
	set_skill("dodge", 30);
	set_skill("shaolin-shenfa", 50);
	set_skill("strike", 60);
	set_skill("banruo-zhang", 60);
	set_skill("parry", 30);
	set_skill("sword", 50);
	set_skill("damo-jian", 50);

	map_skill("force", "yijin-jing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("strike", "banruo-zhang");
	map_skill("parry", "damo-jian");
	map_skill("sword", "damo-jian");

	prepare_skill("strike", "banruo-zhang");

	create_family("少林派", 41, "弟子");

        set("inquiry", ([
		"药理" : (: ask_yaoli :),
		"药性" : (: ask_yaoxing :),
        ]));

	setup();

        carry_object("/d/shaolin/obj/changjian")->wield();
        carry_object("/d/shaolin/obj/xu-cloth")->wear();
}

string ask_yaoli()
{
	switch( random(6) )
	{
	case 0: return "上药一百二十种为君，主养命以应天，无毒，多服久服不伤人。";
	case 1: return "中药一百二十种为臣，主养性以应人，无毒，有毒，斟酌其宜。";
	case 2: return "下药一百二十种为君，主治病以应地，多毒，不可久服。";
	case 3: return "药有君臣佐使，以相宣摄合和者，宜用一君二臣五佐，又可一君三臣九佐使也。";
	case 4: return "药有阴阳配合，子母兄弟，根茎花实草石骨肉。有单行者，有相须者，有相使者，有相畏者，有相恶者，有相反者，有相杀者。凡此七情和合视之，当用相须相使良者，勿用相恶相反者。若有毒宜制，可用相畏相杀者，不尔，勿合用也。";
	case 5: return "药有酸咸甘苦辛五味，又有寒热温凉四气及有毒无毒，阴干暴干，采治时日，生熟，上地所出，真伪陈新，并各有法。";
	}
}

string ask_yaoxing()
{
	object me = this_player();
	int age = (int)me->query("age");

        if (((int)me->query_condition("bonze_drug" ) > 0) || ( me->query("marks/ptz_drug") && ((int)me->query("marks/ptz_drug") == age)))
		return RANK_D->query_respect(me) + "上次服食的灵药药性尚在，万不可贪多务得啊！";
	return "药性有宜丸者，宜散者，宜水煮者，宜酒浸者，宜膏煎者，亦有一物兼宜者，亦有不可入汤酒者，并随药性，不得违越。";
}
