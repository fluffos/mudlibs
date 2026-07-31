//liver.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"女主人"NOR, ({ "nu zhu ren", "ren" }));
	set("shen_type", 1);

	set("str", 19);
	set("gender", "女性");
	set("age", 25);
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
                YEL"能嫁给你这麽一个好丈夫，妾身也很幸福！\n"NOR, 
		YEL"今天的饭还是由我来做吧。嘻嘻！\n"NOR,
        }) );

	add_money("coin", 50);
}

