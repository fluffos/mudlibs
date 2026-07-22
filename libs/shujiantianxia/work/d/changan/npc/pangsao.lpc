// Write By Yanyang@SJ 2001.9.27
// NPC : /d/changan/npc/pangsao.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("胖嫂", ({ "pang sao", "pangsao", "sao" }) );
        set("gender", "女性" );
        set("age", 38);
        set("per", 21);
        set("unique", 1);
        set("long","这位胖嫂正忙著将瓜果分门别类的摆放整齐。\n");
        set("combat_exp", 3000);
        set("attitude", "friendly");
        set("rank_info/respect", "大嫂");
        set("vendor_goods", ({
                (["name": FOOD_D("banana"),"number":5]),
                (["name": FOOD_D("F_pingguo"),"number":5]),
                (["name": FOOD_D("F_baili"),"number":5]),
                (["name": FOOD_D("F_mangguo"),"number":5]),
                (["name": FOOD_D("F_shuimitao"),"number":5]),
                (["name": FOOD_D("F_lizhi"),"number":5]),
                (["name": FOOD_D("F_hamigua"),"number":5]),
                (["name": FOOD_D("F_juzi"),"number":5]),
        }));
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
                        say( "胖嫂笑盈盈地说道：这位" + RANK_D->query_respect(ob)
                                + "，快进来尝尝新鲜的水果吧。\n");
                        break;
                case 1:
                        say( "胖嫂笑盈盈地说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}

void saying(object ob)
{
	if (!ob || environment(ob) != environment()) return;
	if ( file_name(environment(this_object())) != this_object()->query("startroom")) return;

	say("\n胖嫂皱皱眉,说道：对不起,小店今日还没卖出多少水果，请去别处吧！\n\n");
	remove_call_out("kicking");
	call_out("kicking", 1, ob);

}

void kicking(object ob)
{
	if (!ob || environment(ob) != environment()) return;

	ob->move("/d/changan/eastjie3");
	message("vision","只听长长一声叹息，" +  ob->query("name") +
                "无可奈何地离开了花店。\n", environment(ob), ob);
}
