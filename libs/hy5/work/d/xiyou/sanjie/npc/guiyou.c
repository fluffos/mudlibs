// guiyou.c 鬼幽

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"鬼幽"NOR, ({"gui you", "gui"}));
       set("long", "是鬼冥的师兄，但好女人与金钱，武功比他师弟还差。\n");
       set("title", HIC"藏尸地"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 46);
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


	create_family("三界山", 2, "蓝");

	set("inquiry", ([
	"name"     : "我是藏尸地大弟子，你找我有什么事？。\n",
	"here"     : "这里是藏尸地，你这小子想干什么？\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
}

