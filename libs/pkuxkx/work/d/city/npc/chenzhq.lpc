// waiter.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("陈震骐", ({ "chen zhenqi","chen"}) );
	set("gender", "男性" );
	set("age", 32);
     set("start_room","/d/city/yidian");
	set("long",
		"这是扬州城有名的裁缝，老扬州没有不知道他的，每到逢年过节，家里\n"
                "办喜事，他这的生意就好的不得了.\n");
	set("combat_exp", 10000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
		__DIR__"obj/zhja",
		__DIR__"obj/zlq",
		__DIR__"obj/dpdc",
               __DIR__"obj/xscp",
                __DIR__"obj/xhxa",
            __DIR__"obj/qbcs",
            }));

	set("shen_type",1);set("score",200);setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
    add_action("do_list","list");
    add_action("do_buy","buy");
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
            command("bow");
            command("say 这位姑娘，本店有上好的衣服，您这么漂亮也不来几套！");
           }
        else if (ob->query("gender")=="无性")
           {
            command("hi "+ ob->query("id"));
            command("xixi");
            command("say 这位公公，本店有各式男女服装，您也不来几套！");
           }
        else
           {
            command("haha"); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，您是自己买衣服，还是要送给心上人呢？");
           }
           
}

