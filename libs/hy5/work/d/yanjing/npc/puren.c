inherit NPC;

void create()
{
	set_name("ÆÍÈË", ({"puren" }));
	set("gender", "ÄĞĞÔ");
	set("age", 16+random(30));
   
	set("combat_exp", 3000); 
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);

	setup();
	add_money("silver",10);
	carry_object("/clone/cloth/cloth")->wear();
}
	
