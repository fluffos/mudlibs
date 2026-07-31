inherit SUPER_NPC;
#include "guanli.h"

void create()
{
	set_name("菊影",({"shade","juying", "fairy"}));
	set("long",
"翩若惊鸿，婉若游龙，荣曜秋菊，华茂春松。仿佛兮若
轻云之蔽月，飘摇兮若流风之回雪。远而望之，皎若太阳
升朝霞。迫而察之，灼若芙渠出绿波。\n");
       	set("title", "月宫舞仙");
       	set("gender", "女性");
       	set("age", 18);
       	set("class", "xian");
       	set("attitude", "friendly");
       	set("rank_info/respect", "仙姑");
       	set_level(100);
	set_skill("literate", 1000);
	set_skill("unarmed", 1000);
	set_skill("dodge", 1000);
	set_skill("force", 1000);
	set_skill("parry", 1000);
	set_skill("sword", 1000);
	set_skill("spells", 1000);
 	set_skill("moonshentong", 1000);
 	set_skill("baihua-zhang", 1000);
 	set_skill("moonforce", 1000);
 	set_skill("snowsword", 1000);
 	set_skill("moondance", 1000);
        map_skill("spells", "moonshentong");
        map_skill("unarmed", "baihua-zhang");
        map_skill("force", "moonforce");
        map_skill("sword", "snowsword");
        map_skill("parry", "snowsword");
        map_skill("dodge", "moondance");
	create_family("月宫", 2, "弟子");
	set("env/test","HIB");
	set("inquiry", ([
   		"青鸾" : (: ask_guanli :),
	]));
	setup();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"sword",1)->wield();
	powerup();
}

void die()
{
	if( environment() )
	{
		message_vision("\n$N脸色一变，勉力逼住伤势，念动月华真言，化作一道霞光直冲太阴而去！\n\n");
	}
	destruct(this_object());
}