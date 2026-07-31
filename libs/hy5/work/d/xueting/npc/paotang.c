// paotang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("店小二", ({ "pao tang","tang","waiter" }) );
	set("title","饮风客栈");
        set("gender", "男性" );
        set("age", 22);
        set("long","小跑堂里外忙着，还不时要和进来的客人打招呼。\n");
        set("combat_exp", 50);
        set("attitude", "friendly");

        
	set("vendor_goods", ({
		__DIR__"obj/noodles",
		__DIR__"obj/ysd",
		"/d/city/npc/obj/baozi",
	}));
        
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
        if( living(ob = previous_object()) && !is_fighting() && !wizardp(ob))
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_buy", "buy");
	add_action("do_list", "list");
}

void greeting(object ob)
{
	string day_night;
	int time;

	if( !ob
	|| (environment(ob) != environment())
	|| file_name(environment()) != this_object()->query("startroom"))
		return;

	if(!userp(ob) && ob->query("is_beggar"))
	{
		message_vision(CYN"$N冲着$n喊道：这不是你来的地方，赶紧滚！\n"NOR,this_object(),ob);
		ob->go_back_direction();
	}

	
	else
	{
		switch( random(2) )
		{
                case 0:
                        say( CYN"小跑堂笑咪咪地说道：饮风客栈的书讲的好，您一会要好好听听！\n"NOR);
                        break;
                case 1:
                        say( CYN"小跑堂一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n"NOR);
                        break;
		}
	}
}
