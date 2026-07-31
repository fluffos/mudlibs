inherit NPC;

void create()
{
	set_name("ÔÖÃñ", ({"zaiming" }));
	set("gender", "ÄĞĞÔ");
	set("age", 16+random(30));
   
	set("combat_exp", 5000); 
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
	add_money("coin",100);
carry_object("/clone/misc/cloth")->wear();
}
	
