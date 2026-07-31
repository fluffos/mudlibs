// moshuai.c 魔帅

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"魔帅"NOR, ({"mo shuai", "mo"}));
       set("long", "大天魔唯一传人，麾下有两大高手。\n");
       set("title", HIC"天魔宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 50);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "弟子");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
       set("max_force", 1800);
       set("force_factor", 180);
       set("max_mana", 1800);
       set("mana", 1800);
       set("mana_factor", 180);
       set("combat_exp", 1700000);


	create_family("三界山", 2, "蓝");

	set("inquiry", ([
	"name"     : "我是魔帅，大天魔传人。\n",
	"here"     : "这里是天魔宫。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/bintiegun")->wield();
}

