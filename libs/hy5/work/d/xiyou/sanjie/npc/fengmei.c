// fengmei.c 蜂魅

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"蜂魅"NOR, ({"feng mei", "feng"}));
       set("long", "快如魅，毒如蜂，是男人大克星。\n");
       set("title", HIC"天妖宫"NOR);
       set("per", 30);
       set("gender", "女性");
       set("age", 25);
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
        set_skill("throwing", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "我是妖帅麾下九大高手之一。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/dujili")->wield();
}