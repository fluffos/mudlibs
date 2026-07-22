
inherit NPC;

void create()
{
	set_name("水兵", ({ "shui bing", "shui", "bing" }));
	set("shen_type", 1);

	set("gender", "男性");
	set("age", 20);
	set("long", "一个精短打扮的水兵。\n");
	set_skill("cuff", 50);
	set_skill("dodge", 50);
	set_temp("apply/damage", 30);

	set("combat_exp", 16000+random(5000));
	set("attitude", "friendly");

	setup();
	add_money("silver", random(50));
	carry_object(ARMOR_D("armor"))->wear();
}
