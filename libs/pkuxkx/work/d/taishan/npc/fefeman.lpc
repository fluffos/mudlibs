// fefeman.c 朱熹
// ERIC 1996/9/23

inherit NPC;

void create()
{
	set_name("不火不毛", ({ "fefe man", "fefe" }));
	set("long", "这是一位面貌慈祥的老人家，穿着一身布衣，嘴里叼里一根烟斗；\n他啪嗒啪嗒地抽着烟斗，只是偶然间抬起头来；\n便看到他眼中精光一闪而逝，让人心头泛起一阵寒意。\n");
	set("gender", "男性");
	set("age", 65);

	set_skill("literate", 300);

	set_skill("unarmed", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_temp("apply/attack", 80);
	set_temp("apply/defense", 80);
	set_temp("apply/damage", 20);

	set("combat_exp", 400000);
	set("shen_type", 1);
	setup();

	set("chat_chance", 3);
	set("chat_msg", ({
		"不火不毛说道：呃……今天吃得真饱。\n",
		"不火不毛说道：老太婆近来怎么啦……，这个…这个…我都快不行了。\n",
		"不火不毛说道：唉，退休了这么久，骨头都快生锈了，\n也没人来找我主持一下公道什么的，真是闷坏老头子我了。 \n",
		"不火不毛说道：今天去那个房间睡觉好呢？猪圈？\n",
		"不火不毛说道：想当年我还是很厉害的嘛,嘿嘿,无论是打架还是打……………枪！\n",
		"不火不毛说道：那个叫什么杨...杨过的经常和我喝酒,哈,酒量他可不是对手。\n",
		"不火不毛说道：黄鼠狼的拳猜的很好但老夫三招就赢了他。\n",
		"不火不毛说道：青子怎么也打不赢我,唉,不知道现在在哪里快活。\n",
	}) );
}

int recognize_apprentice(object ob)
{
	if (!(int)ob->query_temp("mark/不火不毛"))
		return 0; 
	ob->add_temp("mark/不火不毛", -1);
	return 1;
}

int accept_object(object who, object ob)
{
	if (!(int)who->query_temp("mark/不火不毛"))
		who->set_temp("mark/不火不毛", 0);
	if (ob->query("money_id") && ob->value() >= 1000) {
		message_vision("不火不毛同意跟$N上一回床。\n唉！真是老而弥坚，世风日下，人心不古了。\n", who);
		who->add_temp("mark/朱", ob->value() / 50);
		return 1;
	}
	return 0;
}

