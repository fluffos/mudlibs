// yahuan.c 丫鬟

inherit NPC;

void create()
{
	set_name("丫鬟", ({ "ya huan", "ya", "yahuan" }));
	set("long", "一个小丫鬟，羞答答的样子。\n");
	set("gender", "女性");
	set("age", 17);
	set("per", 23);

	set_skill("unarmed", 20);
	set_skill("dodge", 20);
	set_skill("parry", 20);
	set_temp("apply/attack", 30);
	set_temp("apply/defense", 30);
	set_temp("apply/damage", 5);

	set("combat_exp", 3000);
	set("shen_type", 1);
	setup();
        carry_object(__DIR__"obj/heiyi")->wear();
        carry_object(ARMOR_D("shoes"))->wear();
}
