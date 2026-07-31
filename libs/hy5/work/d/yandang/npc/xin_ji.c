inherit NPC;

void create()
{
	set_name("ĞÔ¼Å", ({ "xin ji", "heshang" }));
	set("gender", "ÄĞĞÔ");
	set("age", 78);

	set("combat_exp", 50000);
	set("shen_type", 1);

	set_skill("unarmed", 100);
	set_skill("blade", 120);
	set_skill("parry", 100);
	set_skill("dodge", 60);
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 15);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/huang_jiasha")->wear();
}
	
