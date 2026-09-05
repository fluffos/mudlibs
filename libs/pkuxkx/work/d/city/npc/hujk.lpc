// waiter.c

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("胡金科", ({ "hu jinke","hu"}) );
	set("gender", "男性" );
	set("age", 36);
	set("long",
		"这位老板长得白白胖胖，和蔼可亲，但是此人却是爱财如命，真是一把\n"
                "好算盘！\n");
	set("combat_exp", 60000);
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
     set("start_room","/d/city/xiaochidian");
      	set("vendor_goods", ({
		__DIR__"obj/qiancg",
		__DIR__"obj/longxg",
		__DIR__"obj/xiaogmt",
                __DIR__"obj/damh",
                __DIR__"obj/huzhzz",
                __DIR__"obj/zuiz",
            }));
       	set("shen_type",1);set("score",500);setup();
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
            command("sister "+ ob->query("id"));
 //           command("admire "+ob->query("id"));
            command("say 您尝尝我们的小吃，一定忘不了！");
        
           }
        else if (ob->query("gender")=="无性")
           {
            command("hi "+ ob->query("id"));
            command("nod");
            command("say 这位公公喜爱鄙店的小吃，真是我们的荣幸！");
           } 
       else {
//            command(""); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，您也爱吃我们店的小吃？真是太好了！");
             }
           
}

