// yang.cg.c
// Rewrote by iszt@pkuxkx, 2007-02-11

#include <ansi.h>

inherit NPC;

string ask_me();
void heal();
void greet();
void create()
{
	set_name("周侗",({"zhou tong", "zhou"}));
	set("long", "周侗年已六十多岁，人很精神，非但书教得好，还会教学生骑马射箭和诸般武艺。\n");
	set("gender", "男性");
	set("age", 64);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 50);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("chat_chance", 14);
	set("chat_msg", ({
		(: heal :),
		(: heal :),
		(: heal :),
		(: heal :),
		(: heal :),
		(: heal :),
		"周侗叹道：「岳飞这孩子，跑到哪去了，招呼也不打一声。」\n",
		"周侗对学生道：「为师有个老友志明长老，一向不曾去看得他，近日准备去看看，你们就不要同去了。」\n",
		"周侗正望着窗外出神，不知想起了什么。\n",
	}));
	set("max_qi", 5000);
	set("max_jing", 4000);
	set("max_neili", 7000);
	set("neili", 7000);
	set("max_jingli", 4000);
	set("jingli", 4000);
	set("jiali", 100);
	set("combat_exp", 12500000);
	set("score", 4000);

	set_skill("force",500);
	set_skill("jiuyang-shengong",500);
	set_skill("dodge",500);
	set_skill("datengnuo-bufa", 500);
	set_skill("hanbing-zhang",500);
	set_skill("parry",500);
	set_skill("sword",500);
	set_skill("qiankun-danuoyi", 500);
	set_skill("strike",500);
	set_skill("spear",500);
	set_skill("yuejia-qiangfa",500);
	map_skill("spear", "yuejia-qiangfa");
	map_skill("strike", "hanbing-zhang");
	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "datengnuo-bufa");
	map_skill("parry", "hanbing-zhang");
	prepare_skill("strike", "hanbing-zhang");
	set("inquiry", ([
		"同去" : (: ask_me :),
		"志明长老" : "志明长老是个有德行的高僧，他在沥泉山，一向不曾去看得他。",
		"看看" : "你要看什么？",
		"老友" : "为师访友，你就不要同去了。",
		"访友" : "为师访友，你就不要同去了。",
		"王明" : "唉，这个东家最喜沽恩挟惠……不说也罢。",
		"沥泉山" : "沥泉山就在本村东北，从王员外家门口向东不远便是。",
		"怪蛇" : "传说西域有人善于培育怪蛇，谁要是搞这种害人的勾当，我见一个杀一个。",
		"岳飞" : "岳飞这孩子，跑到哪去了，招呼也不打一声。",
		"林冲" : "抽风的少年说林冲是我二徒弟，他被奸臣害死了。",
		"卢俊义" : "抽风的少年说卢俊义是我大徒弟，他被奸臣害死了。",
		"周义" : "那是犬子。",
	]) );

	setup();
	carry_object(__DIR__"obj/changqiang")->wield();
	carry_object("/d/mingjiao/obj/changpao")->wear();
}

void heal()
{
	object ob=this_object();
	if (ob->query("eff_qi") < ob->query("max_qi"))
	{
		command("exert heal");
		command("enforce 50");
		return;
	}
	if (ob->query("qi") < ob->query("eff_qi"))
	{
		command("exert recover");
		return;
	}
	if (ob->query("jing") < ob->query("eff_jing"))
		command("exert regenerate");
	return;
}

void init()
{
	object me = this_player();

	if (interactive(me) && !is_fighting()) {
		remove_call_out("greet");
		call_out("greet", 1, me);
	}
}

void greet()
{
	object ob = this_object(), he, room;
	object me = this_player();
	string msg;
	if(ob->query_leader() == me && he = present("zhiming zhanglao", environment(me)))
	{
		command("follow none");
		msg = "$n朗声道：「陕西$n，特来探望。」只见志明长老手持拐杖走将出来，笑脸相迎。\n";
		msg += "$n对$N说道：「你去山上看看吧，我和长老谈些旧话。」\n";
		msg += "$n和志明长老转身一起走进内室。\n";
		me->delete_temp("liquan/ask_zhou");
		me->set_temp("liquan/find_snake", 1);
		room = load_object("/d/qilincun/mingzhai1");
		ob->move(room);
		destruct(he);

		msg += "$N出了门，转到后边。\n";
		message_vision(msg, me, ob);
		room = load_object("/d/qilincun/liquandongqian");
                me->move(room);
	}
	return;
}

string ask_me()
{
	object me=this_player();

	if (me->query_temp("liquan/ask_zhou"))
		return "你还有完没完? 还不快走。";

	if (me->query_temp("liquan/find_yue"))
	{
		me->delete_temp("liquan/find_yue");
		say("周桐笑道：「也罢，既然岳飞有事，又难得这样好天光，就带你去认认那个高僧。」\n");
		this_player()->set_temp("liquan/ask_zhou", 1);
		command("follow " + me->query("id"));
		return "走吧！沥泉山就在本村东北不远。";
	}
	else
		return "你去把岳飞找来，我们一起去看长老。";
}
