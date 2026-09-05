// waiter.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("尹霜叶", ({ "yin shuangye","yin"}) );
	set("gender", "女性" );
	set("age", 18+random(5));
     set("start_room","/d/city/huadian");
        set("per", 25+random(5));
	set("long",
		"这是扬州城有名的花店老板，人称“芙蓉女”的尹霜叶，年纪轻轻，人又漂亮，\n"
                "但是作起生意来却是不让须眉.\n");
	set("combat_exp", 20000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
__DIR__"obj/huashu",
		__DIR__"obj/menrh",
		__DIR__"obj/cejzh",
		__DIR__"obj/taiyl",
                __DIR__"obj/xiufr",
                __DIR__"obj/yitx",
                __DIR__"obj/ziyul",
//                "/clone/gift/lover-rose",
            }));

	setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
    add_action("do_list", "list");
    add_action("do_buy", "buy");
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
        if (ob->query("gender")=="女性")
           {
            command("xixi "+ ob->query("id"));
            command("smile");
            command("say 这位"+RANK_D->query_respect(ob)+"买几盆花回家吧！");
        
           }
        else if (ob->query("gender")=="无性")
           {
            command("xixi "+ ob->query("id"));
            command("bow");
            command("say 这位公公，本店有各式鲜花，您一定满意！");
           }
        else {
            command("smile"); 
            command("say 这位"+RANK_D->query_respect(ob)+"要买什么花呀?");
            command("xixi "+ob->query("id"));
             }
           
}

