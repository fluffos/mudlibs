// mei.c

inherit NPC;
inherit F_DEALER;
#include "/d/beijing/killme.h"
void create()
{
        set_name("梅老板", ({ "mei laoban", "mei", "laoban" }) );
        set("gender", "男性" );
        set("age", 42);
        set("long",
                "这位老板正笑咪咪地忙着，还不时拿起柜台上的算盘拨弄两下。\n");
        set("combat_exp", 600);
        set("attitude", "friendly");
        set("rank_info/respect", "老板");
        set("vendor_goods", ({
                __DIR__"obj/baozi",
        }));
        set("shen_type",1);set("score",500);setup();
        carry_object("/clone/armor/cloth")->wear();

}

void init()
{
        object ob;
        mapping myfam;

        ob = this_player();

        ::init();
        if (base_name(environment()) != query("startroom")) return;
        if( interactive(ob) && visible(ob) && !is_fighting() ) {
                if ( (myfam = ob->query("family"))
                && myfam["family_name"] == "丐帮"
                && ob->query_skill("begging",1) > 10 )
                {
                        remove_call_out("saying");
                        call_out("saying", 0, ob);
                }
                else
                {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }

        add_action("do_buy", "buy");
        add_action("do_list", "list");
}

void greeting(object ob)
{
        if( !ob || environment(ob) != environment() || is_fighting(ob)) return;
        switch( random(2) ) {
                case 0:
                        say( "梅老板笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，快来吃新鲜的包子。\n");
                        break;
                case 1:
                        say( "梅老板用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，快快请进。\n");
                        break;
        }
}


