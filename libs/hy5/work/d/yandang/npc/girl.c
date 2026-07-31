inherit NPC;
inherit F_VENDOR;


void create()
{
	set_name("翠儿", ({ "cuier", "cuier", "cuier" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long",
		"这位翠儿正笑咪咪地忙著。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("no_get", "1");

	set("vendor_goods", ({
		__DIR__"obj/jiu1",
		__DIR__"obj/jiu2",
		__DIR__"obj/jiu3",
	}));
	set("long","一个年轻的姑娘,见你在仔细打量她,羞得低下头去。\n");

	set("area_name","雁荡小酒店");
	set("area_file","/d/yandang/jiudian.c");

	set("inquiry", ([
		"食物" : "对不起,这位客人,小店今日的卤菜卖玩了,您可以到上面\n
观音洞去看看,那里的师傅通常准备有素斋!",
		"吃" : "对不起,这位客人,小店今日的卤菜卖玩了,您可以到上面\n
观音洞去看看,那里的师傅通常准备有素斋!",
		]) );	

        setup();
        carry_object(__DIR__"obj/chu_skirt")->wear();
	add_money("coin", 100);
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	} 

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{

	if( !ob || environment(ob) != environment() ) return;
  message_vision("$N见你过来,忙迎上来，道：这位"+
	RANK_D->query_respect(ob)+"，买碗酒喝吧!\n",this_object());
return;
}



