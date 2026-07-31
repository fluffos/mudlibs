
inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("跑堂", ({ "paotang", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",  "这位跑堂正笑咪咪地忙着，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "伙计");
        set("vendor_goods", ({
		(["name": FOOD_D("jitui"), "number":20]),
		(["name": FOOD_D("jiudai"),"number":20]),
		(["name": FOOD_D("yuebing"),"number":20]),
		(["name": FOOD_D("baozi"), "number":30]),
		(["name": FOOD_D("hdjiudai"),"number":10]),
		(["name": FOOD_D("kaoya"),"number":20])
        }));
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{       
        object ob; 
        ob = this_player();

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob) && visible(ob) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
        }
        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() || is_fighting(ob)) return;
        switch( random(2) ) {
                case 0:
                        say( "跑堂笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "跑堂用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
