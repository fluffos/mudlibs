//guest1.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"客人"NOR, ({ "ke ren", "ren" }));
	set("shen_type", 0);

	set("str", 25);
	set("gender", "男性");
	set("age", 30);
	set("long", "一个出门在外的寻常人。。看上去没有什么特别的。\n");
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
                YEL"这地方真不错。服务态度也好。我还要来光顾。\n"NOR, 
		YEL"老兄，你好象也常来嘛，我见你好面熟。\n"NOR,
        }) );

	add_money("coin", 50);
}

