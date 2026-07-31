inherit NPC;

void create()
{
	set_name("ÅãÁ·µÜ×Ó", ({"dizi" }));
	set("gender", "ÄĞĞÔ");
	set("age", 16+random(30));
	set("combat_exp", 6000+random(2000)); 
	set_skill("parry", 70);
	set_skill("dodge", 70);
       set("str",16);
       set("max_kee",3000);
       set("kee",3000);

	setup();
	add_money("silver",10);
carry_object("/clone/misc/cloth")->wear();
}
	
