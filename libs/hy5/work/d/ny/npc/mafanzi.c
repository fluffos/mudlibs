
// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
   set_name("马贩子", ({ "seller" }) );
	set("gender", "男性" );
	set("age", 22);
        set("cor", 100);
	set("long",
 "只见马贩子不停的忙碌着，还不时的擦擦汗，看来生意不错。\n");
	set("combat_exp", 15000);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");

	setup();
}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(5) ) {
		case 0:
    say( "马贩子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
  + "，要不要买一匹千里马呀?\n");
			break;
		case 1:
    say( "马贩子擦了擦汗，说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n");
			break;
		case 2:
       say( "马贩子说道：这位" + RANK_D->query_respect(ob)
    + "，进来看看马匹吧。这些马可是有名的千里马呀\n");
			break;
		case 3:
     say( "马贩子高声吆喝道:这位" + RANK_D->query_respect(ob)
     + ",马场新开张,所有东西八折出售. \n");
			break;
		case 4:
     say( "马贩子笑呵呵地说道:这位" + RANK_D->query_respect(ob)
   + ",本马场就要倒闭了,跳楼大减价,快来买啊! \n");
			break;
	}
}
