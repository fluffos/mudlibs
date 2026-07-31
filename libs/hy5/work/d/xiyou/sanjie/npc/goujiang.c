// goujiang.c 勾将

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"勾将"NOR, ({"gou jiang", "gou"}));
       set("long", "电将军麾下一名大将，勾法如神。\n");
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
        set_skill("blade", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "我是电将军麾下三大高手之一。\n",
	"here"     : "这里是电府。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/jindao")->wield();
}