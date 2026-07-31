// guest.c 游客

inherit NPC;

void create()
{
	set_name("游客", ({ "you ke", "you" }));
	set("gender", "男性");
	set("age", 20 + random(30));

	set_skill("unarmed", 10);
	set_skill("dodge", 10);
 	set_skill("parry", 10);
	set("combat_exp", 1000+random(2000));
	set("shen_type", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		(: random_move :)
	}) );
	setup();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver", 20);
}
