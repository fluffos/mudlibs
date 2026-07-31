// xuanruhui.c 玄如晦

#include <ansi.h>

inherit NPC;
inherit F_MASTER;

void create()
{
       set_name(HIR"玄如晦"NOR, ({"xuan ruhui", "xuan"}));
       set("long", "忠于天一宫，与大师兄最投缘。惜体弱多病，故武功不高。\n");
       set("title", HIC"天一宫"NOR);
       set("per", 30);
       set("gender", "男性");
       set("age", 63);
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
       set("max_mana", 1500);
       set("mana", 1500);
       set("mana_factor", 120);
       set("combat_exp", 1000000);
       set("daoxing", 1100000);

    

	create_family("三界山", 3, "蓝");
	
	set("inquiry", ([
	"name"     : "我玄如悔是纯阳先师门下第三个弟子。\n",
	"here"     : "纯阳先师为了镇压妖魔，就在这里开山立教，以求灭妖。\n",
	"八卦"     : "我这里就有一个，不过后山是禁地，你不要乱去啊！\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/bagua");
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}

