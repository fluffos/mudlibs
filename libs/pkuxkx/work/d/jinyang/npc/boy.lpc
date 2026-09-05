// kid.c

inherit NPC;

void create()
{
        set_name("小孩",({ "xiao hai", "boy", "kid" }) );
        set("gender", "男性" );
        set("age", random(5));
        set("long", "这是个大胖小子，整体光着屁股满街跑。\n");
		set("str", 10);
        set("dex", 1);
        set("con", 1);
        set("int", 1);
		set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 1);
        set("attitude", "peaceful");
		set("chat_chance", 30);
		set("chat_msg", ({
		(: random_move :)
		}) );

        setup();

}

#include "die.h"