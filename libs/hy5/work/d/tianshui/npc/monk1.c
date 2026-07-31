// monk1.c

inherit NPC;
inherit F_VENDOR;
void create()
{
        set_name("小和尚", ({ "monk"}) );
        set("gender", "男性" );
        set("long","一位十几岁的小和尚，正在向进香的人们卖香。\n");
        set("age", 15);
        set("str", 20);
        set("int", 20);
        set("con", 20);
        set("dex", 20);
        set("combat_exp", 1000);
        set("score", 1000);
        set_skill("dodge", 50);
        set_skill("parry", 50);
        set_skill("literate", 50);

	set("sell_all_day",1);
	set("vendor_goods", ({
	__DIR__"obj/xiang",
	}));    
        setup();
        carry_object(__DIR__"obj/jiasha")->wear();
}
void init()
{	
	object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");   		
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	if(1==2)
	{
		message_vision( "小和尚对$N说道：" + RANK_D->query_respect(ob)+
			"这时候还来敬佛，真是诚心可嘉。\n",ob);
		return;
	}
	message_vision( "小和尚对$N说道：这位" + RANK_D->query_respect(ob)+ "要不要买柱香敬佛。\n",ob);
}
