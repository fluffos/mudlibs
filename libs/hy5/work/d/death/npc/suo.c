// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
void create()
{
        set_name("缇萦", ({ "xiaonu", "nu" }) );
        set("gender", "女性" );
        set("age", 24);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 20);
        set("inquiry", ([
                "孝道" : "身体发肤受之父母，养育之恩，有甚于天，不孝之人，鬼神难容\n",
                "xiao" : "身体发肤受之父母，养育之恩，有甚于天，不孝之人，鬼神难容\n",
        ]) );
        set("long",
"
以孝道而闻名天下的缇萦。
\n"
	);
        set("combat_exp", 1000000);
        set("agi",25);
        set("int",30);
        set("skill_public",1);
	set_temp("apply/attack",200);
	set_temp("apply/defense",250);
        setup();
        carry_object("/clone/misc/cloth")->wear();
}


int is_ghost() { return 1; }

int recognize_apprentice(object ob)
{
        return 1;
}

