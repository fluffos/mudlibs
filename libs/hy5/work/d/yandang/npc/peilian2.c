inherit NPC;

void create()
{
	set_name("ÅãÁ·µÜ×Ó", ({"dizi" }));
	set("gender", "ÄĞĞÔ");
	set("age", 16+random(30));
	set("combat_exp", 1000+random(3000)); 
	set_skill("parry", 50);
	set_skill("dodge", 50);
       set("str",16);
       set("max_kee",3000);
       set("kee",3000);

	setup();
carry_object("/clone/misc/cloth")->wear();
}
	
