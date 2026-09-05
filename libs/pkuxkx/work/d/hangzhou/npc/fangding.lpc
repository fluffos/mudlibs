#include <ansi.h>

inherit NPC;


void create()
{
        set_name("坊丁", ({ "fang ding","ding" }));
		set("title",HIR"孝仁坊"NOR);
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 40);
        set("long",
                "他是这里的坊丁，平时负责打更和缉盗。\n");
        set_skill("unarmed", 15);
        set_skill("dodge", 15);
        set_temp("apply/damage", 10);
        set("combat_exp", 6500);
        set("attitude", "friendly");
		
		setup();
		carry_object("/clone/cloth/cloth")->wear();
}
