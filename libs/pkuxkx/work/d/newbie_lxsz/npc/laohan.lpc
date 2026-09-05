//D:\xkx\d\liuxiu-shanzhuang\npc\laohan.c老汉
// labaz 2012/10/21

inherit NPC;
inherit F_VENDOR;
void greeting(object ob);

void create()
{
	set_name("老汉", ({ "lao han", "laohan" }) );
	set("gender", "男性" );
	set("age", 62);
	set("long", "老汉正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
	set("combat_exp", 1000);
	set("attitude", "friendly");
	set("rank_info/respect", "老大爷");
	set("vendor_goods", ({
		__DIR__"obj/shaodaozi",
		__DIR__"obj/jitui"
        }));

	setup();
}

void init()
{	
	object ob; 
	ob = this_player();

	::init();
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}

	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;

	switch( random(2) ) {
		case 0:
			say( "卖酒老汉笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，进来喝点酒暖暖身子吧。\n");
			break;
		case 1:
			say( "卖酒老汉用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
				+ "，\n请进请进，我们这儿的可都是好酒啊。\n");
			break;
	}
}
