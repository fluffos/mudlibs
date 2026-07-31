inherit NPC;

void create()
{
	set_name("É½×¯µÜ×Ó", ({ "dizi"}));
	set("gender", "ÄĞĞÔ");
	set("age", 23);

	set("combat_exp", 50000);
	set("shen_type", 1);
       set_skill("unarmed", 300);
	set_skill("sword", 300);
	set_skill("parry", 300);
	set_skill("dodge", 300);
       set_skill("force", 30);
	set_temp("apply/attack", 115);
	set_temp("apply/defense", 115);
	set_temp("apply/damage", 120);
create_family("Ñãµ´ÅÉ", 3, "×¯¶¡");


	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
}
	
