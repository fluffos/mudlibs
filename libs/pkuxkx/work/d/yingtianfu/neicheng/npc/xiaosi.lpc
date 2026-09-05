// wujiang.c 武将

inherit NPC;


void create()
{
	set_name("小厮", ({ "xiao si", "xiaosi" }));
	set("gender", "男性");
	set("age", random(10) + 20);
	set("str", 25);
	set("dex", 16);
	set("long", "他是一名小厮，一直在鼓楼打扫。\n");
	set("combat_exp", 50000);
	set("shen_type", 1);
	set("attitude", "peaceful");

	
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/damage", 30);

	set("neili", 400); 
	set("max_neili", 400);
	set("jiali", 10);

	setup();
	
	carry_object("/clone/armor/cloth")->wear();
}

