// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("卖包子的", ({ "seller" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这个卖包子的小贩对你微微一笑，说道：热腾腾的包子，来一笼吧\n");
	set("combat_exp", 30);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
        set("chat_msg", ({
                       "卖包子的吆喝道：包子！热腾腾的包子！\n",
        }) );
                               
	set("vendor_goods", ([
		"包子": "/obj/example/dumpling",
	]) );
	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
//		remove_call_out("greeting");
//		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}
