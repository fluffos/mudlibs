// wangtiejiang.c
//
// Modified by pretty (09/16/98)
//   -- add "ding" action

#include <ansi.h>

inherit NPC;


void create()
{
        set_name("游人", ({ "you ren","ren" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 20+random(50));
        set("long",
                "这是一位乘兴来游西湖的游客。\n");
        set_skill("unarmed", 5);
        set_skill("dodge", 5);
        set_temp("apply/damage", 15);
        set("combat_exp", 2500);
        set("attitude", "friendly");
		set("chat_chance", 20);
		set("chat_msg", ({
			(: random_move :),
		}));
        set("is_xihu_youren",1);
		setup();
		carry_object("/clone/cloth/male2-cloth")->wear();
}
