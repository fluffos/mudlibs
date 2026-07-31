// waiter.c

inherit WAITER;
void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long", "这位店小二正笑咪咪地忙着，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");

        set("per", 15);

        setup();
        carry_object(ARMOR_D("cloth"))->wear();
}

void init()
{
       object ob;

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob = this_player()) && visible(ob) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
        if (!ob || !present(ob, environment())) return;
        switch( random(2) ) {
                case 0:
                        say( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，进来喝杯茶，歇歇腿吧。\n");
                        break;
                case 1:
                        say( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
        }
}

int accept_object(object who, object ob)
{
        if (ob->query("money_id") && ob->value() >= 500) {
                tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
                who->set_temp("rent_paid","喜发客栈");
                return 1;
        }
        return 0;
}

void relay_emote(object me,string arg)
{
        command(arg+" "+me->query("id"));
}
