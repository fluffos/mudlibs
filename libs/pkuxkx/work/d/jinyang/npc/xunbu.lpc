// bj

inherit NPC;
#include <ansi.h>
void create()
{
        set_name("巡捕",({ "xun bu", "xunbu"}) );
        set("gender", "男性" );
        set("age", 25+random(25));
        set("long", "这是个没有带刀的巡捕。\n");
		set("str", 10);
        set("dex", 1);
        set("con", 1);
        set("int", 1);
		set("shen_type", 1);
        set_temp("apply/defense", 10);
        set("combat_exp", 1);
        set("attitude", "peaceful");
        set_skill("sword", 250);
        set_skill("parry",250);
        set_skill("dodge", 250);
        set_skill("force",250);
        set_skill("literate",250);
        set_skill("taiyi-zhang",250);
        set_skill("strike",250);
        set_skill("taiyi-jian",250);
        set_skill("taiyi-shengong",250);
        set_skill("taiyi-you",250);
        

        map_skill("parry","taiyi-zhang");
        map_skill("sword","taiyi-jian");
        map_skill("force","taiyi-shengong");
        map_skill("dodge","taiyi-you");
        map_skill("strike","taiyi-zhang");

        
        prepare_skill("strike","taiyi-zhang");
        
        setup();
        call_out("moving",1);
        carry_object("/clone/misc/cloth")->wear();
}

int moving()
{
    object me=this_object();
    if(me->is_busy() || me->is_fighting())
    {
        return 1;
    }
    else
    {
        this_object()->random_move();
        remove_call_out("moving");
        call_out("moving",80);
        return 1;
    }
}

void init()
{
	object ob;
	::init();
	if (interactive(ob = this_player()) && 
		(int)ob->query_condition("killer")) {
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
}

#include "die.h"