//liver.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"男主人"NOR, ({ "nan zhu ren", "ren" }));
	set("shen_type", 1);

	set("str", 25);
	set("gender", "男性");
	set("age", 30);
	set("long", "一个极平常的城市居民。\n");
	set("combat_exp", 1000);
        set("kee", 150);
        set("max_kee", 150);
	set("attitude", "friendly");
	set_skill("unarmed", 20);
        set_skill("dodge", 20);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 5);
	   
        setup();
	set("chat_chance", 10);
        set("chat_msg", ({
                YEL"能娶到你这麽一个好妻子，夫何何求！\n"NOR, 
		YEL"今天的饭就由我来做吧。呵呵！！\n"NOR,
        }) );

	add_money("coin", 50);
}

