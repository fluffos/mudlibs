// tongyao.c 童妖

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"童妖"NOR, ({"tong yao", "tong"}));
       set("long", "个子矮小，但心恨手辣。\n");
       set("title", HIC"天妖宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 14);
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
        set_skill("dagger", 80);  
        set_skill("force", 80);   

	set("inquiry", ([
	"name"     : "我是妖帅麾下九大高手之一。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/dagger")->wield();
}