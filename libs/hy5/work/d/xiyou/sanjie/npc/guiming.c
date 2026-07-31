// guiming.c 鬼冥

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIW"鬼冥"NOR, ({"master guiming", "master"}));
       set("long", "是鬼幽师弟，不过他勤于练功，功夫比他师弟强多了。\n");
       set("title", HIC"藏尸地"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 40);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "鬼王");
       set("max_kee", 2000);
       set("max_gin", 100);
       set("max_sen", 2000);
       set("force", 3000);
       set("max_force", 3000);
       set("force_factor", 300);
       set("max_mana", 2400);
       set("mana", 2400);
       set("mana_factor", 270);
       set("combat_exp", 2400000);
       set("daoxing", 3500000);



	create_family("三界山", 1, "蓝");
	
	set("inquiry", ([
	"name"     : "老夫乃鬼冥，鬼幽师弟。\n",
	"here"     : "此乃藏尸地，没有其他事情别乱跑。\n",
	]));
	
	set("time", 1);
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
}

