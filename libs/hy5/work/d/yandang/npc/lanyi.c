// biaotou.c 财主管家

inherit NPC;

void create()
{
	set_name("蓝衣少年", ({ "shaonian", "lanyishaonian" }));
	set("gender", "男性");
	set("age", 18);

	set("combat_exp", 10000);
	set_skill("unarmed", 50);

	set_skill("parry", 50);
	set_skill("dodge", 50);

	
	setup();
add_money("silver",10);
	carry_object(__DIR__"obj/lan_cloth")->wear();
}
