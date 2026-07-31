// paotang.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("小伙计", ({ "huo ji" }) );
        set("gender", "男性" );
        set("age", 22);
        set("long","小伙计里外忙着，还不时要和进来
的客人打招呼。\n");

	set("sell_all_day",1);
        set("combat_exp", 50);
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
	add_action("do_buy", "buy");
	add_action("do_list", "list");
	::init();
        if( living(ob = previous_object()) && random(2) && !is_fighting() && !wizardp(ob))
	{
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
}

void greeting(object ob)
{
	say( CYN"小跑堂一哈腰说道：这位" + RANK_D->query_respect(ob)
		+ "，请进请进。\n"NOR);
}