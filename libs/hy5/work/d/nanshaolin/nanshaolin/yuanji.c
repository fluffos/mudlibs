// yuanji.c
// Last Modified by winder on May. 29 2001

#include "yuan.h";
inherit NPC;
inherit F_MASTER;

void create()
{
	set_name("元忌", ({ "yuan ji", "ji", "yuan" }));
	set("long","他是一位中等个子的和尚，身穿一袭青布镶边袈裟。太阳穴微凸，双目炯炯有神。\n");
	set("nickname", "般若院庄严罗汉");
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");

	set("age", 30);
	set("shen_type", 1);
	set("str", 30);
	set("int", 20);
	set("con", 30);
	set("dex", 20);
	set("max_qi", 1500);
	set("max_jing", 600);
	set("neili", 1200);
	set("max_neili", 1200);
	set("jiali", 50);
	set("combat_exp", 200000);
	set("score", 3000);

	set_skill("literate", 100);
	set_skill("buddhism", 100);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("yijinjing", 100);
	set_skill("dodge", 100);
	set_skill("shaolin-shenfa", 100);
	set_skill("cuff", 100);
	set_skill("luohan-quan", 100);
	set_skill("blade", 100);
	set_skill("xiuluo-dao", 100);

	map_skill("force", "yijinjing");
	map_skill("dodge", "shaolin-shenfa");
	map_skill("cuff", "luohan-quan");
	map_skill("blade", "xiuluo-dao");
	map_skill("parry", "xiuluo-dao");
	prepare_skill("cuff", "luohan-quan");

	create_family("南少林派", 20, "弟子");

	setup();
	carry_object(__DIR__"jiedao")->wield();
	carry_object("/d/shaolin/obj/hui-cloth")->wear();
}
void init()
{
	object ob;

	::init();
	add_action("do_nod", "nod");
}

