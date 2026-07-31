// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("关二爷", ({ "master guan", "master" }) );
        set("gender", "男性" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
 	create_family("冥府",2,"义司");
       set("force", 15000);
        set("force_factor", 20);
        set("long",
"
上马金，下马银，不能改其义，千里送嫂，过五关斩六将的关二爷\n"
	);
        set("combat_exp", 1000000);
        set("agi",25);
        set("int",30);
        set_skill("parry", 80);
        set_skill("dodge", 80);
//	set_skill("strategy", 200);
        set_skill("force", 80);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
        setup();
        carry_object("/clone/misc/cloth")->wear();
//        carry_object("cao/obj/cloth")->wear();
}

void attempt_apprentice(object ob)
{
     command("say 好吧，我收下你。\n");
     command("recruit "+ob->query("id"));
     return;
}

int is_ghost() { return 1; }
