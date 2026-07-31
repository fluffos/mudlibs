// yaoshuai.c 妖帅

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"妖哥"NOR, ({"yao ge", "yao"}));
       set("long", "大天妖唯一传人，麾下有九大高手。\n");
       set("title", HIC"天妖宫"NOR);
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

        set_skill("dodge", 80);
      
	create_family("三界山", 3, "蓝");

	set("inquiry", ([
	"name"     : "我是妖帅麾下九大高手之一，也是妖帅之子。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/bintiegun")->wield();
}

