// wangtiejiang.c
//
// Modified by pretty (09/16/98)
//   -- add "ding" action

#include <ansi.h>

inherit NPC;


void create()
{
        set_name("伙计", ({ "huo ji" }));
        set("title", "客栈");
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 45);
        set("long",
                "这是客店的伙计。\n");
        set_skill("unarmed", 10);
        set_skill("dodge", 10);
        set_temp("apply/damage", 15);
        set("combat_exp", 1000);
        set("attitude", "friendly");
    
        setup();
		carry_object("clone/cloth/cloth")->wear();
}
