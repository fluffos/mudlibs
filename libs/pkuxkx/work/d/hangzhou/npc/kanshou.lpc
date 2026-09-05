#include <ansi.h>

inherit NPC;


void create()
{
        set_name("看守", ({ "kan shou","shou" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 20+random(20));
        set("long",
                "这是一名常平仓的看守。\n");
        set_skill("unarmed", 5);
        set_skill("dodge", 5);
        set_temp("apply/damage", 15);
        set("combat_exp", 2800);
        set("attitude", "friendly");
		setup();
		carry_object("clone/cloth/cloth")->wear();
}
