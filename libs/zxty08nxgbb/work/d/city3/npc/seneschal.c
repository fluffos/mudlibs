// seneschal.c
// adams: 1998/06/20
inherit NPC;

void create()
{
        set_name("女管家", ({ "seneschal", "sen" }) );
        set("gender", "女性" );
	set("age", 22);
	set("long",
                "这位女管家正笑咪咪地忙著，还不时敲打着电脑的键盘。\n");
        set("combat_exp", 1000);
	set("attitude", "friendly");
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
                        say( "女管家笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，听听音乐吧。\n");
			break;
		case 1:
                        say( "女管家摘下了自己的眼镜，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
	}
}

