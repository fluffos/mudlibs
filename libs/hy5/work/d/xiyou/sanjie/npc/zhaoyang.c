// zhaoyang.c 朝阳天师

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
string expell_me(object me);

void create()
{
       set_name(HIR"朝阳天师"NOR, ({"master zhaoyang", "master"}));
       set("long", "天一宫掌门大师兄，德高隆重，贵为道教盟主。\n");
       set("title", HIC"天一宫"NOR);
       set("per", 40);
       set("gender", "男性");
       set("age", 30);
       set("class", "sanjie");
       set("attitude", "friendly");
       set("shen_type", 1);
       set("rank_info/respect", "老道长");
       set("max_kee", 1500);
       set("max_gin", 100);
       set("max_sen", 1500);
       set("force", 1800);
 

	
	create_family("三界山", 2, "蓝");
	
	set("inquiry", ([

	"name"     : "我乃天一宫现任掌教大弟子，你可以称呼我朝阳天师。\n",
	"here"     : "这里是天一宫后殿，你迷路了？\n",
	]));	
	
	setup();
	carry_object("/d/xiyou/sanjie/obj/jinjia")->wear();
	carry_object("/d/xiyou/sanjie/obj/qinghong")->wield();
}

