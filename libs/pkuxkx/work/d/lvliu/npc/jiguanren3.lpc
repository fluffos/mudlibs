
inherit NPC;

#include <ansi.h>
#include "jiguanren.h"

void create()
{
        set_name(CYN"机关人"NOR, ({ "jiguan ren", "ren", "robot", }));
		set("long", "一个绿柳山庄看守地牢的机关人，制作精巧，如同真人一般。\n"
		+CYN"他的身上覆盖着厚厚的护甲，双臂上还带着锋锐的刀刃。\n"NOR);
        set("title", NOR "「" CYN "万 " WHT "夫 " YEL "莫 " HIM "开" NOR "」");
        set("race", "机关人");
		set("age", 100);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
        set("max_qi", 1000);
        set("max_jing", 1000);
        set("neili", 1000);
        set("max_neili", 1000);
        set("jiali", 100);
        set("combat_exp", 100000);
		set("max_sk", 80);
		set("no_get", 1);
		set("lvliu_score", 10);
		set("lvliu_npc", 1);
		set("interrupt_busy", 1);
		
		set_temp("apply/damage", 300);
		set_temp("apply/week_injure", 75);
		set_temp("apply/poison_anti_hr", 49);

        set_skill("force", 240);
        set_skill("dodge", 240);
        set_skill("unarmed", 80);
        set_skill("jixie-bi", 80);
        set_skill("parry", 80);
        set_skill("literate", 80);
        set_skill("poison", 80);
		set("jiali", 60);

        map_skill("unarmed", "jixie-bi");
        map_skill("parry", "jixie-bi");

        set("chat_chance", 30);
        set("chat_msg", ({	
			(: killall :),
        }) );		
		set("chat_chance_combat", 30);
		set("chat_msg_combat", ({
			(: auto_perform :),
		}));

        setup();
}
