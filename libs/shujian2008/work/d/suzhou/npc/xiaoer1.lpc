// xiaoer2.c 酒店小二

inherit WAITER;
inherit F_VENDOR;

void create()
{
	set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
	set("gender", "男性" );
	set("age", 22);
	set("long", "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 3800);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		(["name": FOOD_D("xiaren"),"number":20]),
		(["name": FOOD_D("huotui"),"number":20]),
		(["name": FOOD_D("dongsun"),"number":20]),
		(["name": FOOD_D("kaoya"),"number":15]),
		(["name": FOOD_D("jiudai"),"number":18]),
		(["name": FOOD_D("bbaozi"),"number":20])
	}));
	set("inquiry", ([
		"name" : "不敢不敢，小的叫张六，一直在苏州城里的春在楼。\n",
		"rumors" : "最近听说开凿了一条大运河，四同八达，甚是方便，铁匠铺的铁匠知道这事。\n",
		"here" : "这里叫做春在楼，是苏州城里最大的酒楼了。\n",
	]));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
	carry_object(ARMOR_D("shoes"))->wear();
}

void init()
{
	object ob = this_player();

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob) && !is_fighting() ) {
		if ( ob->query("family/family_name") == "丐帮"
		 && ob->query("gb/bags") < 2 ) {
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else {
			remove_call_out("greeting");
			call_out("greeting", 1, ob);
		}
	}
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob) + "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob) + "，请进请进。\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n店小二大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/suzhou/beidajie2");
	message("vision","只听“乒”地一声，" +  ob->query("name") + "被人从春在楼里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
