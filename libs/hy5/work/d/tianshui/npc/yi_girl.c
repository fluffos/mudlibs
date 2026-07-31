// yi_girl.c

inherit NPC;

void create()
{
	set_name("卖艺女孩", ({ "girl" }) );
	set("gender", "男性" );
	set("age", 12);
	set("long", "一个瘦瘦的小女孩，但表演起来却身手敏捷。\n");
	set("per", 35);
	set("combat_exp", 50000);
	set("attitude", "friendly");

	set_skill("unarmed", 50);
	set_skill("parry", 90);
	set_skill("dodge",90);

	setup();
	add_money("coin", 20);
	carry_object("/clone/misc/cloth")->wear();
}
