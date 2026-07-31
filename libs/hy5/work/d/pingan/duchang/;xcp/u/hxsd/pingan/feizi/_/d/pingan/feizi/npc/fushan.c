// chaboshi.c

inherit NPC;

void create()
{
	set_name("富商", ({ "fu shang", "shang" }));
	set("shen_type", 1);
	set("str", 30);
	set("gender", "男性");
	set("age", 45);
	set("long",
		"这是一个富商，长的油头大耳，走在路上气喘吁吁。\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("neili", 500); 
	set("max_neili", 500);
	set("jiali", 10);
	
	setup();
	carry_object("/d/city/obj/cloth")->wear();
}
