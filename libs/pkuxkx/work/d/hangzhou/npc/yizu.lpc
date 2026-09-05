// wangtiejiang.c
//
// Modified by pretty (09/16/98)
//   -- add "ding" action

#include <ansi.h>

inherit NPC;


void create()
{
        set_name("驿丞", ({ "yi cheng","cheng","yicheng" }));
        set("shen_type", 1);
        set("gender", "男性");
        set("age", 40);
        set("long",
                "这是一位驿丞，负责接待抵达临安府的贵客。\n");
        set_skill("unarmed", 15);
        set_skill("dodge", 15);
        set_temp("apply/damage", 10);
        set("combat_exp", 4200);
        set("attitude", "friendly");
		
		setup();
		carry_object("/clone/misc/cloth")->wear();
}
