// xiangyu.c 项羽

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"项羽"NOR, ({"xiang yu", "xiang"}));
       set("long", "一代枭雄，败于刘邦，心生怨恨，千年来冤魂不息。\n");
       set("title", HIC"雷刀门"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "鬼魂");
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
	"name"     : "我是项羽，当年败给刘邦，我誓要仇。\n",
	"here"     : "这里是乌江边，当年我自杀的地方。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/leidao")->wield();
}

