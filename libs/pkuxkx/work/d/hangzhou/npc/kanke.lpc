// wangtiejiang.c
//
// Modified by pretty (09/16/98)
//   -- add "ding" action

#include <ansi.h>

inherit NPC;


void create()
{
        set_name("看客", ({ "kan ke","ke" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 20+random(30));
        set("long",
                "这是一位经常在临安城闲逛的看客。\n");
        set_skill("unarmed", 5);
        set_skill("dodge", 5);
        set_temp("apply/damage", 5);
        set("combat_exp", 2600);
        set("attitude", "friendly");
		set("chat_chance", 20);
		set("chat_msg", ({
			"看客使劲地拍起了自己的巴掌。\n",
		}));
		setup();
		carry_object("clone/cloth/cloth")->wear();
}
