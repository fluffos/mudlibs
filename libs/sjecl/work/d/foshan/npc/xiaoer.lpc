// wanlaoban.c by XiaoYao

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("万老板", ({ "wan laoban", "laoban" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位万老板为刚开张不久的英雄楼忙碌着。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小老板");
        set("vendor_goods", ({
            (["name": FOOD_D("miantiao"),"number" : 20]),
            (["name": FOOD_D("caiyao"),"number" : 20]),
            (["name": FOOD_D("jianjiao"),"number" : 20]),
            (["name": FOOD_D("chazhong"),"number" : 20]),
            (["name": FOOD_D("jiudai"),"number" : 20]),
        }));
        setup();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        add_action("do_list", "list");
        add_action("do_buy", "buy");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() || is_fighting(ob)) return;
        switch( random(2) ) {
                case 0:
                        say( "万老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "万老板用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
}
