// yuan.c

inherit NPC;

void create()
{
	set_name("白猿", ({ "yuan", "monkey"}) );
	set("gender", "雄性");
	set("race", "野兽");
	set("age", 65);
	set("long","这是一只白猿，它身手极为敏捷。\n");
	set("combat_exp", 500000);
	set("shen_type", 1);
	set("attitude", "peaceful");
	set("water", 200);
	set("food", 200);
	set("apply/attack", 100);
	set("apply/defense", 100);
	set("apply/dodge", 100);

	set_skill("unarmed", 725);
	set_skill("parry", 620);
	set_skill("dodge", 620);

	setup();
}
