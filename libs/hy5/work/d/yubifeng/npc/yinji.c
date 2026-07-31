// yinji.c 殷吉

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("殷吉", ({ "yin ji", "ji", "yin" }) );
	set("gender", "男性");
	set("title", "辽东天龙门南宗第六代掌门人");
	set("nickname", "威震天南");
	set("age", 43);
	set("attitude", "friendly");
	set("str", 20);
	set("int", 20);
	set("con", 20);
	set("dex", 20);
	set("combat_exp", 9300000);
set("max_qi", 24000);
	set("max_jing", 22000);
	set("neili", 24000);
	set("max_neili", 24000);
	set("jiali",100);
	set("jingli", 1500);
	set("max_jingli", 1500);
	set("combat_exp", 9000000);
	set("score", 1000);
	set("book_count", 1);
	set("yao_count", 1);
	
	set_skill("unarmed", 200);
	set_skill("sword", 300);
	set_skill("force", 200);
	set_skill("parry", 200);
	set_skill("dodge", 300);
	set_skill("strike", 200);
	set_skill("hand", 200);
	set_skill("buddhism", 350);
	set_skill("medicine", 380);
	set_skill("goplaying", 380);
	set_skill("baiyun-xinfa",380);	
	set_skill("hengshan-jian", 380);
	set_skill("chuanyun-shou",380);
	set_skill("tianchang-zhang",380); 
	set_skill("whip",180); 
	set_skill("rousi-whip",180); 
	set_skill("canxin-jian",388); 
	set_skill("lingxu-bu", 380);
	set_skill("literate", 150);
	
	map_skill("force","baiyun-xinfa");
	map_skill("sword", "canxin-jian");
	map_skill("strike","tianchang-zhang");
	map_skill("hand","chuanyun-shou");
	map_skill("parry", "canxin-jian");
	map_skill("dodge", "lingxu-bu");

	prepare_skill("hand", "chuanyun-shou");
	prepare_skill("strike", "tianchang-zhang");
		  set_temp("apply/armor", 200);
		  set_temp("apply/damage", 200);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);


	setup();
	carry_object("/clone/misc/cloth")->wear();
	carry_object("/clone/weapon/changjian")->wield();
}
