// datianyao.c 大天妖

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"大天妖"NOR, ({"master tianyao", "master"}));
       set("long", "与大天魔一样是邪类，妖中之王。\n");
       set("title", HIC"天妖宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老妖精");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 2400);
       set("max_force", 2400);
       set("force_factor", 240);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 240);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);

 

        create_family("三界山", 1, "蓝");

	set("inquiry", ([
	"name"     : "我就是大天妖，妖中之王。\n",
	"here"     : "这里是天妖宫。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/tianyaojia")->wear();
	carry_object("/d/xiyou/sanjie/obj/yaobang")->wield();
}

