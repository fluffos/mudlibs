// xiaoer2.c 酒店小二
// Rewrote by iszt@pkuxkx, 2007-02-11

inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("酒神张", ({ "jiushen zhang", "jiushen", "zhang" }) );
	set("nickname", "千杯不倒");
	set("gender", "男性" );
	set("age", 22);
	set("long", "这位就是远近闻名的「千杯不倒」了，他正举着酒杯，邀客人痛饮。\n");
	set("combat_exp", 100);
	set("attitude", "friendly");
	set("rank_info/respect", "小二哥");
	set("vendor_goods", ({
		"/clone/food/jitui",
		"/clone/food/jiudai",
		"/clone/food/baozi",
		"/d/riyuejiao/obj/niurou",
	}));
	set("shen_type",-1);
set("score",500);
setup();
}

void init()
{
	object ob; 
	mapping myfam; 

	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		if ( (myfam = ob->query("family"))
			&& myfam["family_name"] == "丐帮" 
			&& environment(this_object())->query("short") == "酒店"
			&& ob->query_skill("begging",1) > 10 )
		{
			remove_call_out("saying");
			call_out("saying", 0, ob);
		}
		else
		{ 
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
	if( !this_object()->visible(ob)) return;
	switch( random(2) ) {
		case 0:
			say( "酒神张笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝杯酒，歇歇腿吧。\n");
			break;
		case 1:
			say( "酒神张举起杯中酒一饮而尽，说道：这位" + RANK_D->query_respect(ob)
				+ "，请了请了。\n");
			break;
	}
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	say("\n酒神张见"+ob->name()+"进来，劝道：「您还是换个地方要饭吧，小店伺候不起。」\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);
	
}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/qilincun/xiaolu1");
	message("vision","只听「乒」地一声，" +  ob->query("name") +
		"被人从酒店里一脚踢了出来，狼狈万状的逃开了。\n", environment(ob), ob);
}