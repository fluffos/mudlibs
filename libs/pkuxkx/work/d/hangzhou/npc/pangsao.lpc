// pangsao.c  by hubo

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("胖嫂", ({ "pang sao","sao"}) );
	set("gender", "女性" );
	set("age", 30);
	set("long",
		"她就是具有一双巧手的胖嫂，她家的点心在杭州可是鼎鼎大名的，据说\n"
                "皇帝老儿小江南时最爱吃她的点心了\n");
	set("combat_exp", 50000);
     set("start_room","/d/hangzhou/dianxinpu");
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
		             __DIR__"obj/cj",
		             __DIR__"obj/sjg",
		             __DIR__"obj/yzh",
            }));
	set("shen_type",1);set("score",200);setup();
	carry_object("clone/cloth/female5-cloth")->wear();
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
        if (ob->query("gender")=="女性")
           {
            command("haha "+ ob->query("id"));
            command("admire "+ob->query("id"));
            command("say 这位姑娘，快来尝尝我的点心，请里面坐！");
        
           }
        else if (ob->query("gender")=="无性")
           {
            command("haha "+ ob->query("id"));
            command("nod");
            command("say 难得公公也来照顾小店的生意，请请！");
           } 
       else {
            command("haha"); 
            command("hi " +ob->query("id"));
            command("say 这位大爷，不是我自夸，全杭州我的点心数第一，您来多少？");
             }
           
}

