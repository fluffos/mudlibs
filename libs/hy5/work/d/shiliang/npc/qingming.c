// shiqing.c

inherit NPC;

void create()
{
	set_name("清明禅师", ({ "shiqing chanshi", "chanshi", "shiqing" }) );
        set("title", "十方寺方丈");
	set("gender", "男性");
	set("age", 20);
	set("long",
		"这是一个满脸横肉的和尚。\n");
	set("combat_exp", 1200000);
        set("shen_type", -1);
	set("attitude", "aggressive");

	set_skill("unarmed", 300);
	set_skill("parry", 300);
	set_skill("blade", 300);
	set_skill("dodge", 300);

	setup();
        carry_object("/d/shaolin/obj/dao-cloth")->wear();
        carry_object("/clone/weapon/gangdao")->wield();
	add_money("silver", 10);
}
