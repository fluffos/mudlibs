// nie.c  by hubo

inherit NPC;
inherit F_DEALER;
void create()
{
	set_name("聂老板", ({"nie"}) );
	set("gender", "男性" );
	set("age", 45);
	set("long",
		"他是临安府城内的杂货铺老板，精明的看着每一个顾客\n");
	set("combat_exp", 50000);
     set("start_room","/d/hangzhou/zahuopu");
	set("attitude", "friendly");
	set("rank_info/respect", "老板");
      	set("vendor_goods", ({
		             __DIR__"obj/cj",
		             __DIR__"obj/sjg",
		             __DIR__"obj/yzh",
                         "/d/xingxiu/npc/obj/case",
            }));
	set("shen_type",1);set("score",500);setup();
	carry_object("clone/cloth/male2-cloth")->wear();
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