// npc: /d/city/npc/wei.c


inherit NPC;

void create()
{
	set_name("韦春芳", ({ "wei chunfang", "chunfang", "wei" }) );
	set("gender", "女性" );
	set("title", "观乐楼老板娘");
	set("age", 42);
	set("long",
		"韦春芳是当朝鹿鼎公兼红花会总舵主韦天宝他娘，虽是徐娘半老，但风韵犹存。\n");
	set("str", 25);
	set("dex", 25);
	set("con", 25);
	set("int", 25);
	set("shen_type", 1);

	set_skill("unarmed", 20);
	set_skill("force", 20);
	set_skill("dodge", 35);

	set("combat_exp", 25000);

	set("max_qi", 300);
	set("max_jing", 100);
	set("neili", 500);
	set("max_neili", 500);

	set("attitude", "friendly");
	set("inquiry", ([
		"韦天宝" : "那是我的乖儿子，长得就像你。",
		"观乐楼" : "我们观乐楼可是扬州城里头一份的听曲去处。",
	]));

	setup();
	set("chat_chance", 15);
	set("chat_msg", ({
		"韦春芳得意地说道：当年老娘我标致得很，弹的一手好琴，不是什么人都可以听老娘弹琴的。\n",
		"韦春芳怒骂道：辣块妈妈，要是罗刹鬼、红毛鬼子到观乐楼来，老娘用\n"
		"大扫帚拍了出去。\n",
		"韦春芳对你说道：你一双眼睛贼忒嘻嘻的，真像那个喇嘛！\n",
	}) );
	carry_object("/d/city/obj/flower_shoe")->wear();
	carry_object("/d/city/obj/pink_cloth")->wear();
}
void init()
{
	object ob;

	::init();

	if (! stringp(query("startroom")) ||
	    find_object(query("startroom")) != environment())
		return;

	if (interactive(ob = this_player()) && !is_fighting())
	{
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object me)
{
	if (! objectp(me) || environment(me) != environment())
		return;

	command("look " + me->query("id"));

	if (me->query("gender") == "无性")
	{
		command("say 你当老娘是什么？太监不得入内！\n");
		command("kick " + me->query("id"));
		message("vision", me->name() +"被韦春芳一脚踢出门外。\n",
			environment(me), ({me}));
		me->move("/d/city/nandajie2");
		message("vision", me->name() + "被人从观乐楼里踢了出来，栽倒在"
			"地上，磕掉两颗门牙。\n", environment(me), ({ me }));

	} else
	{
		if (me->query("class") == "bonze")
		{
			command("say 呦，" + RANK_D->query_respect(me) +
				"也来光顾我们观乐楼啊。");
			command("say 想当年我见过一个西藏喇嘛，他上床前一定要念经，一面念经，眼珠子就骨溜溜的瞧着我。");
		}

		if (me->query("gender") == "女性")
		{
			command("say 哎呀，这年月大姑娘也听曲，成何体统？");
			command("sigh");
		}
		command("say 楼上楼下的姑娘们，速速弹曲！");
	}
	return;
}
