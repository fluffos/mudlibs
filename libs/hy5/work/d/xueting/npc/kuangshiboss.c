// kuangshiboss.c

#include <ansi.h>

inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("矿石商", ({ "kuangshi boss" }) );
//	set("title","    ");
        set("gender", "男性" );
        set("age", 42);
        set("long","想卖什么矿石，找他就对了。\n");
        set("combat_exp", 50);
        set("sell_all_day",1);
        set("attitude", "friendly");


        setup();
	carry_object("/clone/misc/cloth")->wear();
}
