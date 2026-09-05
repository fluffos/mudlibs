inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("逍遥仙子", ({ "xiaoyao xianzi", "xianzi" }) );
        set("gender", "女性" );
        set("age", 16);
		set("per",150);
        set("combat_exp", 20000000);
		set("max_qi",2000000);
		set("max_neili",2000000);
        set("attitude", "friendly");
        set("rank_info/respect", "仙子");
        set("vendor_goods", ({
                 "/d/gift/pal/giftbox",
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
                say("这位" + RANK_D->query_respect(ob) + "，中秋节快乐！\n这次的礼物不能给人也不能拿两次，不然后果自负。\n");
}
