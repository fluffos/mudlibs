// guixianfeng.c 鬼先锋

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"鬼先锋"NOR, ({"gui xianfeng", "gui"}));
       set("long", "雷将军麾下一名先锋，善用妖法。\n");
       set("title", HIC"天魔宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "弟子");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 400);
       set("max_force", 400);
       set("force_factor", 20);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

        set_skill("dodge", 80);
        set_skill("parry", 80);
        set_skill("sword", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "我是雷将军麾下三大高手之一。\n",
	"here"     : "这里是雷府。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}