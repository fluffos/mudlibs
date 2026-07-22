inherit NPC;
inherit F_VENDOR;
 
void create()
{
	set_name("铁匠", ({ "tie jiang", "tie", "jiang" }) );
	set("gender", "男性" );
	set("age", 34);
	set("long", "这是一位正在抡着大铁锤，叮叮当当地打铁的铁匠。\n");
	set("combat_exp", 3000);
	set("attitude", "peaceful");
	set("rank_info/respect", "铁匠");
	set("vendor_goods", ({
                (["name": BINGQI_D("changjian"), "number": 10]),
                (["name": BINGQI_D("gangjian"), "number": 15]),
                (["name": ARMOR_D("armor"), "number": 15]),
                (["name": BINGQI_D("blade"), "number": 15]),
        }));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
        add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(2) ) {
		case 0:
			say( "铁匠笑咪咪地说道：这位" + RANK_D->query_respect(ob)
				+ "，这里只要是铁的家伙，应有尽有。\n");
			break;
		case 1:
			say( "铁匠笑呵呵地说：这位" + RANK_D->query_respect(ob)			+ "，您想要点什么？\n");
			break;
	}
}
