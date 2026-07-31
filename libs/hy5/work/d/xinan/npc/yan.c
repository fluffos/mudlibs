// girl.c
#include <ansi.h>
inherit NPC;



void create()
{
	set_name(HIY"阿研"NOR, ({ "ah yan","yan"}));
        set("gender", "女性" );
        set("title","白族小姑娘");
	set("age", 15);
	set("long",
		"一个漂亮可爱的白族小姑娘。\n");
	set("combat_exp", 600+random(400));
        set("social_exp", 600+random(400));
	set("attitude", "friendly");
        set_temp("apply/attack",20+random(100) );
        set_temp("apply/defense",20+random(100) );
        set_temp("apply/damage",random(5) );
        set_temp("apply/armor",random(5) );
	setup();
       	carry_object(__DIR__"obj/cloth2")->wear();
	add_money("coin", 10);
	set("score",5);
}

