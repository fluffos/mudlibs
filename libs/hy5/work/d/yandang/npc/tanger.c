inherit NPC;

void create()
{
	set_name("棠儿", ({ "tanger", "yahuan" }));
	set("gender", "女性");
	set("age", 16);
   
	set("combat_exp", 1000); 
	set("nickname","丫鬟");
	set_skill("unarmed", 20);
	set_skill("parry", 20);
	set_skill("dodge", 20);
	add_money("silver",10);

	setup();
	carry_object(__DIR__"obj/shiliuqun")->wear();
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
	     say("棠儿笑盈盈道：这位" + RANK_D->query_respect(ob)
	     + "，也是来找我家小姐的么?\n");
	return;
}
	
