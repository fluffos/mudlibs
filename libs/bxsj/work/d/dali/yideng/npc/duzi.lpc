// 书生 by River@SJ 2002.6.5

inherit NPC;
#include <ansi.h>

string ask_me();
string ask_question();

void create()
{
	set_name("书生", ({ "shu sheng", "shu", "sheng" }) );
	set("long", "见他头戴逍遥巾，手挥折叠扇，颏下一丛漆黑的长须，确是个饱学宿儒模样。\n");
	set("gender", "男性" );
	set("age", 45);
	set("str", 25);
	set("con", 25);
	set("dex", 30);
	set("int", 30);
	set("per", 28);
	set("unique", 1);
	set("attitude", "friendly");

	set("max_qi", 5000);
	set("max_jing", 2800);
	set("eff_jingli", 3600);
	set("neili", 8000);
	set("qi", 5000);
	set("jingli", 3600);
	set("max_neili", 8000);
	set("jiali", 50);

	set("combat_exp", 2300000);
	set("score", 5000);

	set_skill("parry", 280);
	set_skill("dodge", 280);
	set_skill("force", 280);
	set_skill("sword", 280);
	set_skill("literate", 200);
	set_skill("qiantian-yiyang", 280);
	set_skill("duanjia-jianfa", 280);
	set_skill("tianlong-xiang", 280);
	set_skill("finger", 280);
	set_skill("yiyang-zhi", 280);
	map_skill("dodge", "tianlong-xiang");
	map_skill("parry", "duanjia-jianfa");
	map_skill("force", "qiantian-yiyang");
	map_skill("finger", "yiyang-zhi");
	map_skill("sword","duanjia-jianfa");
	prepare_skill("finger","yiyang-zhi");

	set("inquiry", ([
		"一灯大师" : (: ask_me :),
		"题目" : (: ask_question :),
	]));
	setup();

	carry_object(BINGQI_D("txs"))->wield();
	carry_object(ARMOR_D("b_cloth"))->wear();
	carry_object(ARMOR_D("caoxie"))->wear();
}

void init()
{
	::init();
	add_action("do_answer", "answer");
}

string ask_me()
{
	object me = this_player();

	if ( me->query_temp("yideng/shusheng_pass"))
		return "这位"+RANK_D->query_respect(me)+"，我师傅就在前面不远处的石屋里。";

	if ( me->query_temp("yideng/ask_shusheng"))
		return "你可回答的出我的问题？";

	me->set_temp("yideng/ask_shusheng", 1);

	return "我出三道题目考考你，若是考得出，那就引你去见我师父，倘有\n"+
		"一道不中，只好请"+RANK_D->query_respect(me)+"从原路回去了。";
}

string ask_question()
{
	object me = this_player();

	if ( me->query_temp("yideng/shusheng_pass"))
		return "这位"+RANK_D->query_respect(me)+"，我师傅就在前面不远处的石屋里。";

	if ( ! me->query_temp("yideng/ask_shusheng"))
		return "这位"+RANK_D->query_respect(me)+"问我题目作甚？";

	if ( me->query_temp("yideng/quest_wait"))
		return "这位"+RANK_D->query_respect(me)+"可能答出我的题目？";

	me->set_temp("yideng/quest_one", 1);
	me->set_temp("yideng/quest_wait", 1);
	return "这里有一首诗，说的是在下出身来历，打四个字儿，你倒猜猜看。\n\n"
		"\t\t六经蕴籍胸中久，一剑十年磨在手。\n"+
		"\t\t杏花头上一枝横，恐泄天机莫露口。\n"+
		"\t\t一点累累大如斗，却掩半床无所有。\n"+
		"\t\t完名直待挂冠归，本来面目君知否？";
}

int do_answer(string arg)
{
	object me = this_player();

	if ( ! arg ) return 0;

	if ( !me->query_temp("yideng/quest_one")
	&& !me->query_temp("yideng/quest_two")
	&& !me->query_temp("yideng/quest_three")) return 0;

	if ( me->is_busy() || me->is_fighting())
		return notify_fail("你正忙着呢。\n");

	if ( me->query_temp("yideng/quest_one") && arg == "辛未状元"){
		me->delete_temp("yideng");
		message_vision(CYN"$N说道：「‘六’字下面一个‘一’一个‘十’，是个‘辛’字。‘杏’字上\n"+
			"加横、下去‘口’，是个‘未’字。半个‘床’字加‘大’加一点，是个‘状’\n"+
			"字。‘完’挂冠，是个‘元’字。辛未状元，失敬失敬，原来是位辛未科的状\n"+
			"元爷。」\n\n"NOR, me);
		command("look "+ me->query("id"));
		command("say 好好，果然不错，下一题，我有一个上联，请"+RANK_D->query_respect(me)+"对对。\n\n"
			"\t\t风摆棕榈，千手佛摇折叠扇。");
		me->set_temp("yideng/quest_two", 1);
		me->set_temp("yideng/ask_shusheng", 1);
		me->set_temp("yideng/quest_wait", 1);
		return 1;
	}
	if ( me->query_temp("yideng/quest_two") && arg == "霜凋荷叶，独脚鬼戴逍遥巾"){
		me->delete_temp("yideng");
		message_vision(CYN"$N游目四顾，只见对面平地上有一座小小寺院，庙前有一个荷塘，此时七月将\n"+
				"尽，高山早寒，荷叶已然凋了大半，心中一动，笑道：「好，我的下联是：霜\n"+
				"凋荷叶，独脚鬼戴逍遥巾。」\n\n"NOR, me);
		command("haha");
		command("say 妙极，妙极！不但对仗工整，而且敏捷之至。");
		command("say 我还有一联，请"+RANK_D->query_respect(me)+"对个下联。\n\n"
			"\t\t琴瑟琵琶，八大王一般头面。");
		me->set_temp("yideng/quest_three", 1);
		me->set_temp("yideng/ask_shusheng", 1);
		me->set_temp("yideng/quest_wait", 1);
		return 1;
	}
	if ( me->query_temp("yideng/quest_three") && arg == "魑魅魍魉，四小鬼各自肚肠"){
		me->delete_temp("yideng");
		message_vision(CYN"$N说道：「这一联是一口气要得罪渔、樵、耕、读四位，我告罪在先，这下联\n"+
				"是：魑魅魍魉，四小鬼各自肚肠。」\n"NOR, me);
		message_vision(CYN"\n$N大惊，站起身来，长袖一挥，向$n一揖到地，说道：「在下拜服。」，转\n"+
				"身纵过小缺口，道：「请罢。」\n", this_object(), me);
		me->set_temp("yideng/shusheng_pass", 1);
		return 1;
	}
	command("shake");
	return 1;
}
