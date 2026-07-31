// /d/yixing/npc/fengliang.c
// Last Modified by winder on Jul. 12 2002

#include <ansi.h>;
inherit F_UNIQUE;
inherit NPC;

void create()
{
	set_name("风良", ({ "feng liang", "feng"}));
	set("title", HIG "青龙门掌门人" NOR);
	set("long", "他是个高大的中年汉子，腰里缠九节鞭。\n");
	set("gender", "男性");
	set("age", 41);
	set("attitude", "peaceful");
	set("shen_type", 1);
	set("per", 22);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
set("str", 35);
	set("int", 30);
	set("cor", 30);
	set("cps", 30);
	set("con", 35);
	set("jing", 24000);
	set("max_jing", 24000);

	set("qi", 24000);
	set("max_qi", 22000);
	set("neili", 25000);
	set("max_neili", 25000);
	set("jiali", 80);
set("combat_exp", 4000000);

	set_skill("force", 150);
	set_skill("whip", 350);
	set_skill("parry", 180);
	set_skill("dodge", 180);
	set_skill("yijinjing", 301);

	set_skill("hunyuan-yiqi", 150);
	set_skill("riyue-bian", 301);
	set_skill("shaolin-shenfa", 180);

	map_skill("force", "hunyuan-yiqi");
	map_skill("whip",  "riyue-bian");
	map_skill("parry", "riyue-bian");
	map_skill("dodge", "shaolin-shenfa");

	set_skill("blade", 150);
	set_skill("claw", 150);
	set_skill("club", 150);
	set_skill("cuff", 150);
	set_skill("finger", 150);
	set_skill("hand", 150);
	set_skill("staff", 150);
	set_skill("strike", 150);
	set_skill("sword", 150);

	set_skill("banruo-zhang", 190);
	set_skill("cibei-dao", 190);
	set_skill("damo-jian", 190);
	set_skill("fengyun-shou", 190);
	set_skill("fumo-jian", 190);
	set_skill("jingang-quan", 190);
	set_skill("longzhua-gong", 190);
	set_skill("luohan-quan", 190);
	set_skill("nianhua-zhi", 190);
	set_skill("pudu-zhang", 190);
	set_skill("qianye-shou", 190);
	set_skill("sanhua-zhang", 190);
	set_skill("weituo-gun", 190);
	set_skill("wuchang-zhang", 190);
	set_skill("xiuluo-dao", 190);
	set_skill("yingzhua-gong", 190);
	set_skill("yizhi-chan", 190);
	set_skill("zui-gun", 190);
	set_skill("buddhism", 200);
	//map_skill("blade", "cibei-dao");
	map_skill("claw", "longzhua-gong");
	//map_skill("club", "wuchang-zhang");
	map_skill("cuff", "luohan-quan");
	map_skill("finger", "nianhua-zhi");
	map_skill("hand", "fengyun-shou");
	//map_skill("staff", "weituo-gun");
	map_skill("strike", "sanhua-zhang");
	//map_skill("sword", "fumo-jian");

     set("chat_chance_combat", 90);
     set("chat_msg_combat", ({
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "finger.fuxue" :),
                (: perform_action, "whip.chan" :),
                (: perform_action, "whip.chanrao" :),
                (: perform_action, "whip.fumoquan" :),
                            }) );
	set("chat_chance", 10);
	set("chat_msg", ({
		"风良说道：丁不四这老贼不许别人使九节鞭，便是和老子过不去！\n",
		"风良说道：长乐帮的司徒大哥与俺们有过命的交情，真想去拜访他老人家。\n",
	}) );

	set("inquiry",([
		"丁不四" : "这老贼竟然把我的九节鞭夺走了。",
		"长乐帮" : "我也正要到长乐帮拜山。",
		"司徒大哥" : "司徒大哥的事就是兄弟我的事。",
		"司徒横" : "听说长乐帮的奸贼作乱饭上害死了他。",
		"九节鞭" : "九节鞭是找不回来了，得另外弄根鞭子当武器用。",
	]));

	setup();
	carry_object(__DIR__"obj/jiujiebian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}


void unconcious()
{
	die();
}
void die()
{
	int i;
        object who = this_object()->query_temp("last_damage_from");
  	if (!who) return;


who->set_temp("book91123",1);
		
		

		
		
	::die();

}  