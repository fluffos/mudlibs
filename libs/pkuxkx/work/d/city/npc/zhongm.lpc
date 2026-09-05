// waiter.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("钟茗", ({ "zhong ming","zhong"}) );
	set("gender", "女性" );
	set("age", 22);
     set("start_room","/d/city/chadian");
        set("per", 23 + random(8));
	set("long",
		"一位年青貌美的茶叶店老板，多少男儿拜倒在她的石榴裙下！\n"
            );
	set("combat_exp", 30000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
             __DIR__"obj/xhlj",
             __DIR__"obj/hsmj",
             __DIR__"obj/tgy",
             __DIR__"obj/jhch",
             __DIR__"obj/erlxzh",
             __DIR__"obj/wlch",
            }));
       	setup();
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
 //           command("admire "+ob->query("id"));
            command("say 这位"+RANK_D->query_respect(ob)+"带包茶叶回去吧！");
        
           }
        else if (ob->query("gender")=="无性")
           {
            command("nod "+ ob->query("id"));
 //           command("nod");
            command("say 这位公公想要买些什么茶叶呢？");
           } 
       else {
//            command(""); 
            command("hi " +ob->query("id"));
            command("say 您来啦！新到的好茶，您不试试？");
             }
           
}

