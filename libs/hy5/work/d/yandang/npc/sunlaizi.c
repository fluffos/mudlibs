
inherit NPC;

void create()
{
	set_name("Ëïñ®×Ó", ({ "sun", "laizi" }));
	set("gender", "ÄĞĞÔ");
	set("age", 35);

	set("combat_exp", 2000);
        set("shen_type",-1);

	set_skill("unarmed", 20);
	set_skill("blade", 30);
	set_skill("parry", 32);
	set_skill("dodge", 30);
	
	set_temp("apply/attack", 6);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 20);

	setup();
carry_object("/clone/weapon/gangdao")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
	
