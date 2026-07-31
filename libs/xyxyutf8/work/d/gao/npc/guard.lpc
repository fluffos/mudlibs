inherit SUPER_NPC;

void create()
{
	set_name("土匪头目", ({"bandit leader", "bandit", "leader"}));
	set("long","清风寨的小头目。\n");
	set("gender", "男性");
	set("age", 28);
	set_level(20);
	set("attitude", "aggressive");
	set("per", 25);
	set("force_factor", 15);
	set_skill("parry", 140);
	set_skill("dodge", 140);
	set_skill("unarmed", 200);
	set_skill("yanxing-steps",100);
	set_skill("force",140);
	set_skill("changquan",200);
	set_skill("ningxie-force",100);
	map_skill("force","ningxie-force");
	map_skill("dodge", "yanxing-steps");
	map_skill("unarmed", "changquan");
	map_skill("parry", "changquan");
        set("chat_chance", 2);
        set("chat_msg", ({
		"小头目大喊：太岁头上动土，不想活了！\n",
	}) );
	setup();
        carry_object(0,"unarmed",random(3))->wield();
	carry_object("/d/gao/obj/piyi")->wear();
}
