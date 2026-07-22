// /d/fuzhou/npc/xiaoer.c 客栈小二

inherit WAITER;

inherit F_VENDOR;
void create()
{
        set_name("小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 27);
        set("long", "这位店小二正笑咪咪地忙着，还不时拿起挂在脖子上的抹布擦脸。\n");
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("vendor_goods", ({
                (["name": MISC_D("denglong"), "number":10]),
                (["name": MISC_D("fire"), "number":10]),
        }));
        set("inquiry", ([
                "name" : "不敢当，称呼我小二就好了。",
                "rumors" : "我可不知道什么传闻，这种事，你去茶馆好了。",
                "here" : "这里就是福州城内最大的客栈：“吉祥客栈”。",
                "福州" : "这就是福州呀，客官您这不是骑驴找驴吗？",
        ]));
        set("per", 20);

        set("chat_chance", 2);
        set("chat_msg", ({
		"店小二嚷声说道，“客官！里面请，里面请！”\n",
		"店小二笑嘻嘻地说道，“住咱们吉祥客栈，您就放心吧。”\n",
        }) );
        setup();
        carry_object(ARMOR_D("cloth"))->wear();
        carry_object(ARMOR_D("shoes"))->wear();
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
        add_action("do_list", "menu");
        add_action("do_list", "list");
        add_action("do_buy", "buy");
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

        if (ob->query("money_id") && ob->value() >= 500){
                tell_object(who, "小二一哈腰，说道：多谢您老，客官请上楼歇息。\n");
                who->set_temp("rent_paid","吉祥客栈");
                return 1;
        }
        return 0;
}

void relay_emote(object me,string arg)
{
        command(arg+" xiao er");
}
