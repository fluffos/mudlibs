// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("常胜将军", ({ "master yue", "master" }) );
        set("nickname", HIY"金盔"HIW"银甲"NOR);
        set("gender", "男性" );
        set("age", 44);
        set("str", 50);
        set("cor", 30);
        set("cps", 30);
        set("int", 30);
	create_family("冥府",2,"义司");
            set("per", 30);
	set("attitude","friendly");
        set("max_force", 15000);
        set("force", 15000);
        set("force_factor", 20);
        set("long",
"
你看着看着，觉得这位将军就象是当年统兵十万，直捣黄龙，壮志未酬的岳飞！
\n"
	);
        set("combat_exp", 1000000);
        set("agi",25);
        set("int",30);

        set_skill("parry", 80);
        set_skill("dodge", 80);
        set_skill("force", 80);
//   	  set_skill("leadership", 200);
        set_skill("literate", 60);
        set("skill_public",1);
	set_temp("apply/attack",200);
	set_temp("apply/defense",200);
        setup();
        carry_object(__DIR__"obj/goldarmor")->wear();
        carry_object(__DIR__"obj/silverarmor")->wear();
}


int is_ghost() { return 1; }

int recognize_apprentice(object ob)
{
        if( ob->query("marks/不忠") )
	{
		say("将军喝道：我最恨的就是你这种不忠之人！\n");
		kill_ob(ob);
		ob->kill_ob(this_object());
		return 0;
	}
        if( ob->query("marks/忠") )
                return 1;
        return 0;
}
void attempt_apprentice(object ob)
{
     command("say 好吧，我收下你。\n");
     command("recruit "+ob->query("id"));
     return;
}


