// /d/yixing/npc/cl_bei.c 贝海石
// Last Modified by winder on Jul. 12 2002

inherit NPC;

#include <ansi.h>

void create()
{
	set_name("贝海石", ({ "bei haishi", "bei" }));
	set("nickname", "着手成春");
	set("party/party_name", HIC"长乐帮"NOR);
	set("party/rank", "总管");
	set("long", 
		"他是一个身穿黄衫的老人，看上去脸色苍白，说话有气无力，\n"
		"还不停的咳嗽着，便似身患重病一般。\n");
	set("gender", "男性");
	set("age", 50);
	set("attitude", "friendly");
	set("shen_type", -1);
	set("str", 25);
	set("int", 30);
	set("con", 28);
	set("dex", 28);

	set("max_qi", 111900);
	set("max_jing", 111500);
	set("neili", 111700);
	set("max_neili", 111700);
	set("jiali", 140);
	set("combat_exp", 11200000);
	set("score", 1118000);

	set_skill("force", 500);
	set_skill("dodge", 500);
	set_skill("parry", 500);
	set_skill("cuff",  520);
/*
	set_skill("ding-force",  100);
	set_skill("wuxingbu",   100);
	set_skill("wuxing-quan", 120);

	map_skill("force", "ding-force");
	map_skill("dodge", "wuxingbu");
	map_skill("cuff",  "wuxing-quan");
	map_skill("parry", "wuxing-quan");

	prepare_skill("cuff", "wuxing-quan");
*/
	set("inquiry", ([
		"长乐帮" : "长乐帮的具体事务由我总管。",
		"入帮" : "你去问帮主吧。",
		"武功" : "帮主老人家的武功比我强多了，你还是向帮主学吧。",
		"香主" : "各位香主的任命由帮主老人家说了算。",
		"司徒横" : "我对我们帮主老人家的景仰之情，有如滔滔江水连绵不绝。",
		"帮主" : "我家帮主司徒大爷乃威镇江南的“东霸天”也。",
	]));

	setup();

	carry_object("/clone/misc/cloth")->wear();
}

