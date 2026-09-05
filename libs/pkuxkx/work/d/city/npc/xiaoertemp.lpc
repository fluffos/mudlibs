// waiter.c
//为icer结婚发喜糖用，过几天改回xiaoer.c
inherit NPC;

void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地忙著，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        setup();
}

void init()
{       

        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        object xitang;
        
        if( !ob || environment(ob) != environment() ) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
                        break;
        }
        if (!ob->query("icer/xitang") && !ob->query_temp("icer/get_xitang"))
        {
                xitang = new("/u/icer/obj/xitang");

                message_vision("店小二乐呵呵地对$N说：您可赶上好日子了，icer为了庆祝结婚，\n正在四处发喜糖，当然也缺不了您的！\n",ob);

                message_vision("店小二拿出一包喜糖，取出一颗，递给$N，说道：这是您的，您拿好！\n",ob);
        ob->set_temp("icer/get_xitang",1);
                xitang->move(ob);
        }
}

int accept_object(object who, object ob)
{
        
        if (ob->query("money_id") && ob->value() >= 5000) 
        {
                tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");

                who->set_temp("rent_paid",1);

                return 1;
        }

        return 0;
}

