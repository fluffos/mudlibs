// File         : iszt.c
// Created By   : iszt@pkuxkx, 2007-01-06

inherit NPC;
#include <ansi.h>

void create()
{
	set_name("十兆", ({ "shi zhao", "iszt", }));
	set("gender", "男性");
	set("long", CYN"传说中此人曾于官场芸芸众生之中异军突起，一举成为"HIC"大内第一高手"NOR+CYN"。\n"
		"在武林之中叱咤风云，改变了一个时代。此后却急流勇退，据说有人瞧\n"
		"见成仙去了，不知为何此时又在这里出现。\n"NOR);
	set("title", HIW "雪山派第七代长门弟子" NOR);
	set("attitude", "peaceful");
	set("no_get", 1);
	set("age", 20);
	set("shen_type", 1);
	set("shen", 141414);
	set("str", 26);
	set("int", 40);
	set("con", 30);
	set("dex", 28);
	set("kar", 50);
	set("per", 40);
	set("max_qi", 14000);
	set("max_jing", 14000);
	set("max_neili", 41000);
	set("neili", 41000);
	set("max_jingli", 41000);
	set("jingli", 41000);
	set("combat_exp", 200000000);
	set("score", 100000);
	set("dagou-bang/tiao", 1);
	set("dagou-bang/zhuan", 1);

	set_skill("force", 2000);
	set_skill("xueshan-neigong", 1000);
	set_skill("dodge", 2000);
	set_skill("yanling-shenfa", 1000);
	set_skill("strike", 1000);
	set_skill("xingxiu-duzhang", 1000);
	set_skill("throwing", 1000);
	set_skill("liuyang-zhang", 1000);
	set_skill("parry", 2000);
	set_skill("qiankun-danuoyi", 400);
	set_skill("staff", 1000);
	set_skill("dagou-bang", 1000);
	set_skill("whip", 1000);
	set_skill("duanyun-bian", 1000);
	set_skill("sword", 1000);
	set_skill("xueshan-jianfa", 1000);
	set_skill("dugu-jiujian", 1000);
	set_skill("buddhism", 800);
	set_skill("literate", 1000);

	map_skill("force", "xueshan-neigong");
	map_skill("dodge", "yanling-shenfa");
	map_skill("parry", "qiankun-danuoyi");
	map_skill("strike", "xingxiu-duzhang");
	map_skill("throwing", "liuyang-zhang");
	map_skill("staff", "dagou-bang");
	map_skill("whip", "duanyun-bian");
	map_skill("sword", "xueshan-jianfa");
	map_skill("staff", "dagou-bang");

	prepare_skill("strike", "xingxiu-duzhang");

	set("inquiry", ([
		"name" : "兄弟十兆有礼了。",
		"十兆" : "正是在下。",
		"here" : "这里是扬州比武场，打死人不偿命的地方。",
		"比武场" : "这里是扬州比武场，打死人不偿命的地方。",
		"rumors" : "我来到这里还不算大事么？",
		"advent" : "行云是猪头，对吧？",
		"行云" : "行云是猪头，对吧？",
		"猪头" : "猪头就是你的头。",
		"雪山派" : "春节估计雪山派就要开始收徒了。",
		"凌霄城" : "凌霄城就是……具体的你问别的弟子吧！",
		"巫师" : "找巫师有什么事，去武庙西北的会客室说吧。",
		"bug" : "你想利用bug么？",
		"香蕉" : "嗯。",
		"banana" : "嗯。",
		"蒙古奸细" : "嗯。",
		"mgjx" : "嗯。",
	]));
	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"十兆胸有成竹的说道：「你们没一个是我的对手。」\n"NOR,
		CYN"十兆冷冷的瞧着在场众人，轻蔑的哼了一声。\n"NOR,
	}) );
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: perform_action, "staff.chan" :),
		(: perform_action, "staff.tiao" :),
		(: perform_action, "staff.zhuan" :),
		(: perform_action, "sword.liuchu" :),
		(: perform_action, "sword.liuchu" :),
		(: perform_action, "sword.chandou" :),
	}));
	setup();
	carry_object("/clone/weapon/yuxiao")->wield();
	carry_object("/clone/weapon/zhubang")->wield();
	carry_object("/clone/weapon/changbian");
	carry_object(__DIR__"npc/obj/jiudai");
	carry_object("/d/lingxiao/npc/obj/changpao")->wear();
}