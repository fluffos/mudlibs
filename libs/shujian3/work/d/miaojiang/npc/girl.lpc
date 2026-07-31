inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("苗家女子", ({ "miaojia nuzi","girl" }) );
        set("gender", "女性" );
        set("age", 16);
        set("long",
                "这位一个苗族小姑娘，年纪随小，可神情老到。\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "小贩子");
        set("vendor_goods", ({
            (["name": FOOD_D("mangguo"),"number" : 20]),
            (["name": FOOD_D("lizhi"),"number" : 20]),
            (["name": FOOD_D("longyan"),"number" : 20]),
            (["name": FOOD_D("yangtao"),"number" : 20]),
            (["name": FOOD_D("xiangjiao"),"number" : 20]),
        }));
        setup();
        add_money("coin", 90);
	carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{       
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
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
                        say( "苗家女子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，别走的那么匆忙，我这里有好多水果卖，一定有你喜欢吃的。\n");
                        break;
                case 1:
                        say( "苗家女子笑呵呵地说：这位" + RANK_D->query_respect(ob)
                                + "，您想挑点什么水果？\n");
                        break;
        }
}
