// lizhaocai.c

inherit NPC;

void create()
{
	set_name("李招财", ({ "li zhaocai", "zhaocai","li","lizhaocai"}) );
	set("gender", "男性" );
	set("age", 32);
	set("long",
		"他身材微瘦，正笑咪咪地招呼客人，手下十分利落，透着精干。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("unique", 1);

	set("inquiry", ([
		"吐蕃" : "这里就是了，客官是来办事还是旅游呀？有向导没有？",
		"吐蕃国" : "这里就是了，客官是来办事还是旅游呀？有向导没有？",
		"向导" : "里屋拉琴的肖老头在这里生活了多年，你可以找他。",
		"大雪山" : "出城往西，具体多远这我也说不好。",
		"大轮寺" : "在大雪山顶，那里是我们吐蕃的护国禅寺。",
		"大雪山大轮寺" : "在大雪山顶，那里是我们吐蕃的护国禅寺。",
		"皇宫" : "正修建着呢，听说因为人手不够，有不少囚犯都被押去干活。",
		"鸠摩智" : "呀，你怎么敢直呼大轮明王的名字，小心让士兵听到把你抓起来。",
		"法王" : "山上大轮寺里有很多，不知道你问哪一位？",
		"金轮法王" : "他受封了“蒙古国第一国师”，去草原了，最近我也没见过他。",
		"宗赞王子" : "他武艺超群，吐蕃贵族的姑娘哪个不想嫁他，这两天他在皇宫那里监工吧。",
		"宗赞" : "你说的是我们吐蕃国的宗赞王子么？",
		"招财大车店" : "那不正是小号么？",
                "囚犯" : "都是些战争中的俘虏和还不起债的人，真正的坏蛋没多少。",
	]) );
	setup();

        set("chat_chance", 3);
        set("chat_msg", ({
"李招财得意地说道：“前两天，金轮法王和两个蒙古官路过我这里，光打赏就给我二两黄金。”\n",
"李招财叹息着道：“天气这么冷，这么多囚犯没吃饭还要干体力活，真是可怜。”\n",
"李招财伸出右大姆指, 道：“大轮明王真是活佛再世，每年都有这么多人来听法。”\n",
"李招财小声说道：“宗赞王子脑筋是不是不太灵光，竟把野草认成雪莲花。”\n",
"李招财怒冲冲, 道：“那五个恶徒要再来捣乱，说什么我也得告官去了。”\n",
"李招财笑嘻嘻地说道：“听说西夏的银川公主这两天来吐蕃游玩，不知道是真是假。”\n",
"李招财低声道： “那几个血刀门的僧人向来不守戒律，不知道前几天失踪的妇女跟他们有没有关系。”\n",
        }) );
        carry_object(ARMOR_D("pipao"))->wear();
}

void init()
{	
	object ob;

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if (!ob || !present(ob, environment())) return;
	switch( random(2) ) {
		case 0:
			say( "李招财笑眯眯地道：外面天寒地冻，这位" + RANK_D->query_respect(ob)
				+ "，进屋喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "李招财点头哈腰的说道：屋里炕烧得热热的，这位" + RANK_D->query_respect(ob)
				+ "进来暖活暖活吧。\n");
			break;
	}
}

int accept_object(object who, object ob)
{
	
	if (ob->query("money_id") && ob->value() >= 500) 
	{
		tell_object(who, "李招财乐得嘴都快豁了，说道：您老赶快里屋请吧。\n");
		who->set_temp("rent_paid",1);
		return 1;
	}
	return 0;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
