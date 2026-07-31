// kanyaodizi 看窑弟子
// Made By keepon at 99.08.15

inherit NPC;

string ask_work1();
string ask_work2();
string ask_houshan();

void create()
{
	set_name("看窑弟子", ({ "kanyao dizi", "di zi", "dizi", "kanyao" }));
	set("long", "他是峨嵋山的第五代弟子，是在此看守炭窑的。\n");
	set("gender", "男性");
	set("title", "峨嵋派第五代弟子");
	set("age", 30);
	set("str", 50);
	set("int", 20);
	set("con", 20);
	set("dex", 50);
	set("combat_exp", 100000);
	set("shen", 0);
	set("attitude", "peaceful");
	set("max_qi",1800);
	set("max_jing",1800);
	set("neili",1600);
	set("max_neili",1600);
	set("jiali",10);

	set_skill("sword", 80);
	set_skill("huifeng-jian", 80);
	set_skill("parry",80);
	set_skill("linji-zhuang", 80);
	set_skill("dodge", 80);
	set_skill("force", 80);
	set_skill("anying-fuxiang",80);

	map_skill("force", "linji-zhuang");
	map_skill("dodge", "anying-fuxiang");
	map_skill("parry", "huifeng-jian");
	map_skill("sword", "huifeng-jian");

	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set("inquiry", ([
		"伐木": (: ask_work1() :),
		"烧炭": (: ask_work2() :),
//		"后山": (: ask_houshan() :),
//		"修炼": (: ask_houshan() :),
	]) );

	setup();
	carry_object("/d/emei/obj/cloth2")->wear();
	carry_object("/d/emei/obj/shoes2")->wear();
	carry_object("/d/emei/obj/changjian")->wear();
}

string ask_work1()
{
	object me=this_player();
	int lvl = (int)me->query_skill("linji-zhuang", 1);

	if( me->query("family/family_name") != "峨嵋派" || me->query("class") == "bonze" )
		return "这位"+ RANK_D->query_respect(me) + "不是峨嵋俗家弟子，怎敢劳动您的大驾？";
	if ( lvl > 100 )
		return "你的功力太高，这些粗活还是让低辈弟子去干吧。";
	if( me->query_temp("emjob2/伐木") )
		return "不是已经叫你去了吗？怎么还在这闲呆着？";
	me->set_temp("emjob2/伐木", 45 - ((int)me->query("str")) );
	return "峨嵋派的弟子就得吃苦耐劳。好吧，你这就到后山树林里弄一些木柴来。";
}

string ask_work2()
{
	object me=this_player();
	int lvl = (int)me->query_skill("linji-zhuang", 1);
	if( me->query("family/family_name") != "峨嵋派" || me->query("class") == "bonze" )
		return "这位"+ RANK_D->query_respect(me) + "不是峨嵋俗家弟子，怎敢劳动您的大驾？";
	if ( lvl > 100 )
		return "你的功力太高，这些粗活还是让低辈弟子去干吧。";
	if( (int)me->query_temp("emjob2/伐木") != 1)
		return "你最好先弄些可以作炭的木材来。";
	if( me->query_temp("emjob2/烧炭") )
		return "不是已经叫你去干了吗？怎么还闲呆着？";
	me->set_temp("emjob2/烧炭", 10 + random((int)me->query("per")));
	me->set_temp("emjob2/uptime", uptime() );
	return "好吧，你就在这烧炭吧。";
}

string ask_houshan()
{
	object me=this_player();
	int lvl = (int)me->query_skill("linji-zhuang", 1);
	if ( (int)lvl/10 == 14 ) me->set("emsujia", 0);
	if ( (int)lvl/10 == 16 ) me->set("emsujia", 1);
	if ( lvl < 140 ) return "后山有一个山洞是修炼的最好场所，但你的内功还不到火候。\n";
	tell_object(me, "既然你问到了，那我就带你去吧。\n");
	me->move("/d/emei/houshanxlsd");
	return "又一个好苗子。\n";
}
