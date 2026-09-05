// waiter.c

inherit NPC;
#include <ansi.h>;


void create()
{
        set_name("店小二", ({ "xiao er", "xiao", "waiter" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long",
                "这位店小二正笑咪咪地招呼着客人。\n");
        set("combat_exp", 100);
        set("attitude", "friendly");
        set("rank_info/respect", "小二哥");
        set("shen_type",1);set("score",200);setup();
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
        if( !ob || environment(ob) != environment() ) return;
        if( !this_object()->visible(ob)) return;
		if (base_name(environment(this_object()))!="/d/saiwai/jiujia") return;
		switch( random(2) ) 
		{
			case 0:
			write( "店小二笑咪咪地说道：这位" + RANK_D->query_respect(ob)
                                + "，赶路饿了吧？小店各色菜式都有，可以随意点(order)，呵呵。\n");
			break;
			case 1:
			write( "店小二用脖子上的毛巾抹了抹手，说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n");
			break;
        }
}
