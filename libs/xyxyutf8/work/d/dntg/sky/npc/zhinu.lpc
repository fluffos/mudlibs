#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIM"织女"NOR, ({"zhi nu", "zhinu", "xian"}));
	set("long","西王母的外甥女。因为私自下凡与牛郎相爱，而被罚银河永隔，\n只有每年的七月初七才能鹊桥相会。\n");
	set("gender", "女性");
	set("age", 20);
	set("class", "xian");
	create_family("月宫", 2, "弟子");
	set("title", "");
	set("attitude", "friendly");
	set("rank_info/respect", "仙姑");
	set_level(130);
	set("per", 35);
	set("int", 30);
	set("force_factor", 50);
	set("mana_factor", 80);
	set("daoxing", 2000000);
	
	set_skill("literate", 140);
	set_skill("unarmed", 120);
	set_skill("dodge", 180);
	set_skill("force", 120);
	set_skill("parry", 120);
	set_skill("blade", 150);
	set_skill("xuanhu-blade", 150);
	set_skill("spells", 120);
	set_skill("moonshentong", 120);
	set_skill("baihua-zhang", 120);
	set_skill("moonforce", 120);
	set_skill("moondance", 200);
        
	map_skill("spells", "moonshentong");
	map_skill("unarmed", "baihua-zhang");
	map_skill("force", "moonforce");
	map_skill("blade", "xuanhu-blade");
	map_skill("parry", "xuanhu-blade");
	map_skill("dodge", "moondance");
	set_temp("armor_level",60);
   	set_temp("weapon_level",60);
	setup();
	carry_object(0,"neck",1)->wear();
	carry_object(0,"ring",1)->wear();
	carry_object(0,"cloth",1)->wear();
	carry_object(0,"shoes",1)->wear();
	carry_object(0,"blade",1)->wield();
}
