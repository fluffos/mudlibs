// xiaofan.c

inherit NPC;

void create()
{
	set_name("小贩", ({ "xiao fan","fan" }) );
	set("gender", "男性" );
	set("age", 21);
	set("long",
		"趁着大家都来看戏，卖点零食挣点钱。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	setup();
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
			message_vision( "小贩冲着$N点头哈腰：这位" + RANK_D->query_respect(ob)
				+ "也来看戏了。\n",ob);
			break;
		case 1:
			message_vision( "小贩笑眯眯的对$N说道：这位" + RANK_D->query_respect(ob)
				+ "要不要买点吃喝？\n",ob);
			break;
	}
}
