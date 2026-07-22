// xiaofan.c 小贩子

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("小贩子", ({ "xiao fan", "xiao", "fan" }) );
        set("gender", "男性" );
        set("age", 34);
        set("long",
                "这位小贩子正笑咪咪地来回忙著，还不时招呼过往的客人进来。\n");
        set("combat_exp", 300);
        set("attitude", "peaceful");
        set("rank_info/respect", "小贩子");
        set("vendor_goods", ({
        (["name":__DIR__"obj/bottle","number":15]),
        (["name":__DIR__"obj/zhujian","number":18]),
        (["name":__DIR__"obj/fire","number":15]),
        (["name":__DIR__"obj/zhubang","number":10])
        }));
        setup();
        add_money("coin", 90);
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
                        say( "小贩子笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，别走的那么匆忙，我这里一定有你想要的东西。\n");
                        break;
                case 1:
                        say( "小贩子笑呵呵地说：这位" + RANK_D->query_respect(ob)
                                + "，您想要点什么？\n");
                        break;
        }
}

