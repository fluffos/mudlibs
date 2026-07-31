inherit NPC;

void create()
{
	set_name("游客", ({"youke" }));
	set("gender", "男性");
	set("age", 20+random(20));
   
	set("combat_exp", 2000); 
	set_skill("unarmed", 23);
	set_skill("parry", 24);
	set_skill("dodge", 26);

	setup();
add_money("silver",1);
	carry_object("/clone/misc/cloth")->wear();
}
void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}
void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
	command("ah");
			break;
		case 1:
	say("行遍天下,此处风景独奇,真是天工造物.\n");
			break;
                           }
}
	
