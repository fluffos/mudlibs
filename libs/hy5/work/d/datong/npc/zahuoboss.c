// zahuoboss.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;


void create()
{
	set_name("胡迈", ({ "hu mai","boss" }) );
	set("title","杂货铺老板");
        set("gender", "男性" );
        set("age", 42);
	set("sell_all_day",1);
        set("long","这是一位瘦小枯干的中年人。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");
        set("vendor_goods",({
		__DIR__"obj/rope",
        }));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
		

        add_action("do_list", "list");
        add_action("do_buy", "buy");
	
        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	switch( random(2) )
	{
		case 0:
			say( CYN"刘金风说道：这位" + RANK_D->query_respect(ob)
				+ "，请进请进。\n"NOR);
			break;
		case 1:
			say( CYN"刘金风说道：这位" + RANK_D->query_respect(ob)
				+ "要买点什么？\n"NOR);
			break;
	}
}