inherit NPC;

void create()
{
	set_name("·¨¿Õ", ({ "fa kong", "kong" }));
	set("gender", "ÄĞĞÔ");
	set("age", 56);

	set("combat_exp", 10000);
	set("shen_type", 1);

	set_skill("unarmed", 50);
	set_skill("blade", 80);
	set_skill("parry", 50);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 13);
	set_temp("apply/defense", 13);
	set_temp("apply/damage", 13);

	setup();
	carry_object("/clone/weapon/gangdao")->wield();
	carry_object(__DIR__"obj/qing_jiasha")->wear();
}
	
