// cowboy.c

inherit NPC;
void create()
{
	set_name("牧童", ({ "mu tong", "tong" }) );
	set("gender", "男性" );
	set("age", 17);
	set("long", "一个天真活泼牧童。 \n");
	set("combat_exp", 7000);
	set("per", 30);
	set("attitude", "friendly");
	set_skill("parry", 40);
	set_skill("dodge", 40);
	set_skill("unarmed",10);
	setup();
	add_money("coin", 5);
	carry_object("/clone/misc/cloth")->wear();
}