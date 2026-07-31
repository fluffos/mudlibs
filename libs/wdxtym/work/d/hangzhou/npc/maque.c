// Doing

inherit NPC;

void create()
{
	set_name("麻雀", ({ "maque" }) );
	set("race", "野兽");
	set("age", 3);
	set("long", "一只棕色的麻雀。\n");
	set("attitude", "peaceful");

	set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 200);
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 2);
	set_temp("apply/armor", 1);

	set("chat_chance", 10);
	set("chat_msg", ({
		"麻雀飞上飞下。\n",
	}) );

	setup();
}
