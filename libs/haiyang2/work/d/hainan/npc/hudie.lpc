#include <ansi.h>
inherit NPC;
int *names = ({YEL,RED,GRN,CYN,HIB,WHT,HIG,});

void create()
{      
        set_name(names[random(sizeof(names))]+"蝴蝶"+NOR, ({ "hudie", "huahudie" }) );
        set("race", "野兽");
	set("gender", "雌性");
        set("age", 5);
	set("long", "一只五彩美丽的蝴蝶。\n");
        set("attitude", "friendly");
	set("chat_chance", 30);
	set("chat_msg", ({
		(: this_object(), "random_move" :),
		"蝴蝶在花丛中翩翩起舞。\n",
                         }));		

	set("str", 5);
	set("con", 20);
        set("limbs", ({ "头部", "身体", "翅膀" }) );
        set("verbs", ({ "bite"}) );

	set_skill("dodge", 20);
        set_temp("apply/armor", 1);

        setup();
}

