#include <ansi.h>
inherit NPC;
int *names = ({YEL,RED,GRN,CYN,BLU,WHT,HIG,});

void create()
{      
        set_name(names[random(sizeof(names))]+"花蝴蝶"+NOR, ({ "hudie", "huahudie" }) );
        set("race", "野兽");
	set("gender", "雌性");
        set("age", 2);
	set("long", "一只五彩美丽的蝴蝶。\n");
        set("attitude", "friendly");
	set("str", 5);
	set("con", 20);
        set("limbs", ({ "头部", "身体", "翅膀" }) );
        set("verbs", ({ "bite"}) );

	set_skill("dodge", 20);
        set_temp("apply/armor", 1);

        setup();
}

