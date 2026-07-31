// piaoyou.c

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("票友", ({ "piao you", "piao", "you" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long",
		"这位聚精会神地看着戏，你要是过去打招呼，他肯定会不耐烦的。\n");
	set("combat_exp", 1500);
	set("attitude", "peaceful");
	set("rank_info/respect", "票友");
	
	setup();
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
			say( "票友自言自语地说：“看呀，多棒的戏，真是比在家呆着强多了。”\n");
			break;
		case 1:
			say( "票友对着你悄悄地说：这位" + RANK_D->query_respect(ob)
				+ "，千万别告诉我老婆我在这里。\n");
			break;
	}
}
