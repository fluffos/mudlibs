// /d/tianshui/npc/tea boss.c

#include <ansi.h>

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("茶师", ({ "tea boss","boss" }) );
        set("gender", "男性" );
        set("age", 39);
        set("long","茶师手里拎着一个龙嘴大茶壶里外忙着，还不时和客人打招呼。\n");
        set("combat_exp", 200);
        set("attitude", "friendly");
	set("vendor_goods", ({
		"/d/city/npc/obj/jitui",
		"/d/city/npc/obj/jiudai",
		"/d/city/npc/obj/baozi",
	}));
        setup();
	carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

	::init();
	add_action("do_buy", "buy");
	add_action("do_list", "list");		
        if( living(ob = previous_object()) && !is_fighting() )
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
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
                        say( CYN"茶师笑咪咪地说道：欢迎光临，小店各种名茶俱全，请进请进。\n"NOR);
                        break;
                case 1:
                        say( CYN"茶师一哈腰说道：这位" + RANK_D->query_respect(ob)
                                + "，请进请进。\n"NOR);
                        break;
		}
	}
}