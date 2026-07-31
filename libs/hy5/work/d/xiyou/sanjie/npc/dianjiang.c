// dianjiang.c 电将军

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"电将军"NOR, ({"dian jiang", "dian"}));
       set("long", "欲成为魔族之王，率领铁将、火将、勾将为天魔服务。\n");
       set("title", HIC"天魔宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 50);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "弟子");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

   

	create_family("三界山", 3, "蓝");

	set("inquiry", ([
	"name"     : "我是魔帅麾下两大高手之一。\n",
	"here"     : "这里是电府。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/bintiegun")->wield();
}

