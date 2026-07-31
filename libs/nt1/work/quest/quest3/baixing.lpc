// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit NPC;

void create()
{
        NPC_D->generate_cn_name(this_object());

        if (random(2))
                set("gender", "男性");
        else
                set("gender", "女性");

        set("no_get", 1);
        set("title", HIW "无辜百姓" NOR);
        set("waiting", "lonely");   
        set_skill("force", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("unarmed", 60);
        set_skill("taiji-shengong", 60);
        map_skill("force", "taiji-shengong"); 
        
        add_temp("apply/defense", 500);
        add_temp("apply/armor", 500);

        set("no_suck", 1);
        set_temp("quest_ob", 1);
        
        set("max_neili", 1000);
        set("neili", 1000);     
        set("max_qi", 1000);
        set("max_jing", 1000);  
        set("combat_exp", 50000); 
        
        setup();
        
        carry_object("/clone/misc/cloth")->wear();
        remove_call_out("escape_me");
        call_out("escape_me", 120, this_object());
}

void escape_me(object ob)
{
        destruct(ob);
}

void unconcious()
{
        this_object()->die();
}

void die()
{
        object ob, me, killer;

        me = this_object();
        
        if (! ob = find_player(me->query("waiting"))) 
                find_living(me->query("waiting"));

        if (ob && ob->query("slough/task"))
        {
                killer = find_living(ob->query("slough/id"));
                if (killer) 
                        killer->set_temp("baixing_killed", 1);
        }

        message_vision(HIC "$N惨号一声，倒在地上死了！\n" NOR, me);
        remove_call_out("escape_me");
        destruct(me);
}

