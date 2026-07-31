// huanwangzi.c 幻忘子

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"幻忘子"NOR, ({"huan wangzi", "huan"}));
       set("long", "喜性荣华富贵，不甘修道清贫，投靠魔道，为虎作伥。\n");
       set("title", HIC"天一宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 65);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老道长");
       set("max_kee", 1000);
       set("max_gin", 100);
       set("max_sen", 1000);
       set("force", 1200);
       set("max_force", 1200);
       set("force_factor", 120);
       set("max_mana", 1200);
       set("mana", 1200);
       set("mana_factor", 120);
       set("combat_exp", 1200000);
     

	create_family("三界山", 3, "蓝");
	
	set("inquiry", ([
	"name"     : "你可以叫我幻忘子。\n",
	"here"     : "这里不是好地方，如果想荣华富贵，可以跟我一起走。\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}
