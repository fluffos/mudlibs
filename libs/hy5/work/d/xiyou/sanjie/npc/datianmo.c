// datianmo.c 大天魔

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"大天魔"NOR, ({"master tianmo", "master"}));
       set("long", "与大天妖一样是邪类，妖中之王。\n");
       set("title", HIC"天魔宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老魔头");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 3000);
       set("mana", 3000);
       set("mana_factor", 30);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

  

        create_family("三界山", 1, "蓝");

	set("inquiry", ([
	"name"     : "我就是大天魔，魔中之王。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/shihun")->wield();
}

