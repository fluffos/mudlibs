
inherit NPC;

#include <ansi.h>
#include "jiguanren.h"

void create()
{
        set_name(HIC"机关人"NOR, ({ "jiguan ren", "ren", "robot", }));
		set("long", "一个绿柳山庄看守地牢的机关人，制作精巧，如同真人一般。\n"
		+HIC"他的体型比其他机关人整整大上一倍，身上覆盖着一层铁甲。\n"NOR);
        set("title", NOR "「" CYN "万 " WHT "夫 " YEL "莫 " HIM "开" NOR "」");
        set("race", "机关人");
		set("age", 100);
        set("str", 50);
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
		set("last_jiguanren", 1);
		
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
