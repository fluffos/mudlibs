//Cracked by Roath
// gaibang npc code

inherit NPC;

void create()
{
	set_name("赵狗儿", ({"zhao gouer", "zhao", "gouer"}));
	set("title", "丐帮一袋弟子");
	set("gender", "男性");
	set("age", 16);
	set("long", 
		"这是衣衫褴屡的小乞丐，老是缩在路边昏昏沉沉地打磕睡。\n");
	set("attitude", "peaceful");
	set("str", 22);
	set("int", 20);
	set("con", 25);
	set("dex", 26);

	set("rank", 1);

	set("max_qi", 120);
	set("max_jing", 120);
	set("neili", 30);
	set("max_neili", 30);
	set("jiali", 3);
	
	set("combat_exp", 2000);
	
	set_skill("force", 12); 
	set_skill("huntian-qigong", 10); 
	set_skill("strike", 10); 
	set_skill("dodge", 10); 
	set_skill("parry", 70); 
	set_skill("begging", 30); 
	set_skill("stealing", 40); 
	set_skill("checking", 10); 
	
	map_skill("force", "huntian-qigong");
	map_skill("dodge", "xiaoyaoyou");
	
	create_family("丐帮", 20, "弟子");
	setup();

	carry_object("/d/gaibang/obj/budai")->wear();
}

#include "/kungfu/class/gaibang/promote.h"
