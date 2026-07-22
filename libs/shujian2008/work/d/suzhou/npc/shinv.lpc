// shinv.c 侍女

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("侍女", ({ "shi nv", "nv", "waiter" }) );
        set("gender", "女性" );
        set("age", 22);
        set("long",
                "一脸聪明乖巧，满口伶牙俐齿。见有人稍微示意，便过去加茶倒水。\n");
        set("combat_exp", 3800);
        set("attitude", "friendly");
	set("vendor_goods", ({
		(["name": FOOD_D("mitao"),"number":15]),
		(["name": FOOD_D("cichawan"),"number":10])
	}));
	setup();
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
	object ob = this_player();

	::init();
	if (base_name(environment()) != query("startroom")) return;
	if( interactive(ob) && !is_fighting() ) {
		if ( ob->query("family/family_name")== "丐帮"
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
			say( "侍女笑着说道：这位" + RANK_D->query_respect(ob) + "，进来喝杯茶，歇歇腿吧。\n");
			break;
		case 1:
			say( "侍女说道：这位" + RANK_D->query_respect(ob) + "，请进请进。\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n侍女大喝一声：你这臭要饭的进来干什麽？ 给我滚出去！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/suzhou/nandajie1");
	message("vision","只听“乒”地一声，" +  ob->query("name")+ "被人从茶馆里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}
