// NPC : /d/wudang/npc/youke.c 游客
// Lklv 2001.9.28 Modify

inherit NPC;

void create()
{
	set_name("游客", ({ "you ke", "youke", "ke" }));
	set("gender", "男性");
	set("age", 20 + random(30));

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set("apply/attack", 15);
	set("apply/defense", 15);
	set("apply/damage", 5);
	set("combat_exp", 750);
	set("shen_type", 1);

	setup();

        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
	add_money("silver", 5);
}
