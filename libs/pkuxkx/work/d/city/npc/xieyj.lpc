// waiter.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("谢一绝", ({ "xie yijue","xie"}) );
	set("gender", "男性" );
	set("age", 42);
     set("start_room","/d/city/xiemaodian");
	set("long",
		"这是扬州城有名的鞋王，据说祖上经营这个行业已经三代了\n"
                "到了他这一代，生意越来越大，连帽子生意也作了起来\n");
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
		__DIR__"obj/qbmx",
		__DIR__"obj/bdkx",
             __DIR__"obj/lcxhx",
                __DIR__"obj/htm",
                __DIR__"obj/qctj",
             __DIR__"obj/qzd",
               
            }));

	set("shen_type",1);set("score",500);setup();
}

void init()
{	
	object ob;

	::init();
      add_action("do_list", "list");
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
            command("say 这位姑娘里面请，本店有各式鞋样，您看看喜欢什么!");
            
           }
    
      else if (ob->query("gender")=="无性")
           {
            command("hi "+ ob->query("id"));
            command("xixi");
            command("say 这位公公里面请，小店备有各式男女鞋帽，请随便挑!");
            
           }       
        else
           {
            command("haha"); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，请进请进，你想要点什么，尽管吩咐!");
           }
           
}

