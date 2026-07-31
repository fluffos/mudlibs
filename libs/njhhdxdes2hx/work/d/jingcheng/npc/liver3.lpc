//liver3.c
//by dwolf 

#include <ansi.h>

inherit NPC;

void create()
{
        set_name(YEL"秀才"NOR, ({ "xiu cai" }));
	set("shen_type", 1);

	set("str", 25);
	set("gender", "男性");
	set("age", 16);
	set("long", "他家虽然不富裕也不穷，但他读书很努力，年纪轻轻就成了秀才\n");
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
                YEL"老吾老以及人之老，幼吾幼以及人之幼。\n"NOR, 
		YEL"会当凌绝顶，一览众山小。\n"NOR,
        }) );

	add_money("coin", 100);
}

