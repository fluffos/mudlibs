inherit NPC;

void create()
{
	set_name("Ñ¾÷ß", ({"yahuan" }));
	set("gender", "Å®ĞÔ");
	set("age", 16);
   
	set("combat_exp", 1000); 
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	add_money("silver",10);

	setup();
	carry_object(__DIR__"obj/shiliuqun")->wear();
}
	
