// qi.c 风者
// By Lgg,1998.10

#include <ansi.h>;
#include "sanxiu.h"

inherit NPC;
inherit F_MASTER;

void create()
{
	set_name(HIC"小灵儿"NOR, ({"xiao qi", "qi"}));
	set("gender", "女性");
	set("class", "taoist");
	set("nickname", HIM"仙女"NOR);
	set("age", 24);
	set("long",
		HIW"这是一位来自天上的天仙，她长相十分甜美，让人一见就心生喜欢。\n"NOR);
	set("attitude", "friendly");
	set("shen_type",1);
	set("str", 500);
	set("int", 500);
	set("con", 500);
	set("dex", 500);

	set("chat_chance_combat", 60);

	set("qi", 200000000);
	set("max_qi", 200000000);
	set("jing", 200000000);
	set("max_jing", 200000000);
	set("neili", 30000);
	set("max_neili", 30000);
	set("jiali", 600);

	set("combat_exp", 220000);

	set_skill("force", 600);
	set_skill("xuantian-wuji", 180);
	//set_skill("qiang", 600);
	//set_skill("bawang-qiang", 60);
	//set_skill("cunxin-quan", 120);
	set_skill("dodge", 600);
	//set_skill("bawang-qiang", 60);
	set_skill("parry", 600);
	//set_skill("bawang-qiang", 60);
	set_skill("literate",600);
	set_skill("chansi-shou", 180);
	set_skill("chuixue-jian", 180);
	set_skill("dashou-yin", 180);

	map_skill("force", "xuantian-wuji");
	//map_skill("qiang", "bawang-qiang");
	//map_skill("dodge", "bawang-qiang");
	//map_skill("parry", "bawang-qiang");

	create_family("散修", 5, "一阶散修");

	setup();

	carry_object("/clone/weapon/green_sword")->wield();
	carry_object("/d/quanzhen/npc/obj/grayrobe")->wear();

}

void attempt_apprentice(object ob)
{

   ob=this_player();
       
      
   if ((int)ob->query("zhuanshi") < 1) 
        {
                command("say 我不收弱者！");
                return;
        }

	command("say 好吧，我就收下你这个徒弟了。");
	command("recruit " + ob->query("id"));
	command("say 好！很好！我散修又多了一大助力。！");
	ob->set("title", HIR "散修奇人" NOR);
}
