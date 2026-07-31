// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// zhike.c 知客

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("知客道长", ({ "zhike daozhang", "zhike" }));
        set("long", 
                "他是武当山的知客道长。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);

        set("str", 20);
        set("int", 20);
        set("con", 25);
        set("dex", 20);
        
        set("max_qi", 400);
        set("max_jing", 200);
        set("neili", 500);
        set("max_neili", 500);

        set("combat_exp", 7500);
        set("score", 1000);

        set_skill("force", 40);
        set_skill("yinyun-ziqi", 40);
        set_skill("dodge", 40);
        set_skill("strike", 40);
        set_skill("wudang-zhang", 40);
        set_skill("parry", 40);
        set_skill("sword", 40);
        set_skill("wudang-jian", 20);
        set_skill("taoism", 20);

        map_skill("parry", "wudang-jian");
        map_skill("sword", "wudang-jian");
        map_skill("strike", "wudang-zhang");

        prepare_skill("strike", "wudang-zhang");

        set("chat_chance",2);
        set("chat_msg", ({
                "知客道长说道：我武当地灵人杰，香火鼎盛，普天下的人都来朝拜敬香。\n",
                "知客道长说道：玄岳门乃武当出入门户，我等一定要精心守卫(volunteer)，不可丝毫懈殆。\n"
        }));

        create_family("武当派", 4, "弟子");

        setup();
        carry_object("/d/wudang/obj/greenrobe")->wear();
        carry_object("/clone/weapon/changjian")->wield();
}

void init()
{
        ::init();
        add_action("do_volunteer", "volunteer");
}

int do_volunteer()
{
        object me = this_player();
        object *ob;
        object *obs; 
        int i;

        if (me->query_temp("in_guard")) 
                return notify_fail("知客道长对你说：你专心守好山门，别想打两份工。\n");

        if (me->query("family/family_name") != "武当派")
        {
                message_vision("知客道长大喝一声：作为别派的弟子，我怎么放心你呢？！\n", me);
                return 1;
        }
        
        ob = all_inventory(environment(me));
        obs = filter_array(ob, 
                           (: interactive($1) && 
                           $1 != $(me) && 
                           $1->query_temp("in_guard") && 
                           environment($1) :)); 

        if (sizeof(obs) > 3)
                return notify_fail("知客道长对你说：已经有不少人守山门了，你一会再来吧。\n");

        tell_room(environment(me), me->query("name") + "开始在武当山门值守。\n");
        set("qi", 30000);
        set("jing", 30000);
        me->set_temp("in_guard", 1); 
        
        // remove_call_out("end_guard");
        call_out("end_guard", 150, me);
        // remove_call_out("clone_meng");
        call_out("clone_meng", 30, me);
        return 1;
}

void clone_meng(object me)
{
        object ob;
        int maxskill;
        int maxexp;
        int maxqi;
        
        if (! me) return;

        if (! me->query_temp("in_guard")) 
                return;

        maxskill = me->query_skill("force", 1);
        maxqi = me->query("eff_qi");
        maxexp = me->query("combat_exp");
        
        if (environment(me)->query("short") != "玄岳门")
        {
                tell_object(me,"你在武当山门值守走开，失败。\n");
                call_out("end_guard", 0, me);
                return;
        }

        tell_room(environment(me), "山下突然冲上来一伙蒙面大汉。\n");

        ob = new("/d/wudang/npc/mengmian.c");
        if (! me->is_ghost())
        {
                ob->move(environment(me));
        }
        ob->set("combat_exp", maxexp);
        if (maxskill > 5 && maxexp > 50000) 
        {
                ob->set_skill("kuang-jian", maxskill*1/2);
                ob->set_skill("sword", maxskill*1/2);
                ob->set_skill("parry", maxskill*1/2);        
                ob->set_skill("unarmed", maxskill*1/2);
                ob->set_skill("dodge", maxskill*1/2);        
        } else 
        {
                ob->set_skill("kuang-jian", 5);
                ob->set_skill("sword", 5);
                ob->set_skill("parry", 5);        
                ob->set_skill("unarmed", 5);
                ob->set_skill("dodge", 5);        
        }
        ob->set("qi",maxqi);        

        ob->set("title", HIR "蒙面大汉" NOR);
        ob->kill_ob(me);
        message_vision(HIR "\n$N对着$n大叫一声，杀啊!。\n" NOR, ob, me); 
        tell_room(environment(me), "山下突然冲上来一伙蒙面大汉。\n");
        
        ob = new("/d/wudang/npc/mengmian.c");
        if (! me->is_ghost())
        {
                ob->move(environment(me));
        }

        ob->set("combat_exp", maxexp);
        if (maxskill > 5 && maxexp > 50000) 
        {
                ob->set_skill("kuang-jian", maxskill*2/3);
                ob->set_skill("sword", maxskill*2/3);
                ob->set_skill("parry", maxskill*2/3);        
                ob->set_skill("unarmed", maxskill*2/3);
                ob->set_skill("dodge", maxskill*2/3);        
        } else 
        {
                ob->set_skill("kuang-jian", 5);
                ob->set_skill("sword", 5);
                ob->set_skill("parry", 5);        
                ob->set_skill("unarmed", 5);
                ob->set_skill("dodge", 5);        
         }
        ob->set("qi", maxqi);        
        
        ob->set("title", HIR "蒙面大汉" NOR);
        ob->kill_ob(me);
        me->kill_ob(ob);
        message_vision(HIR "\n$N对着$n大叫一声，杀啊!。\n" NOR, ob, me); 

        call_out("clone_meng", 100, me);
}

void end_guard(object me)
{
        if (! me) return;

        if (! me->query_temp("in_guard")) return;

        me->delete_temp("in_guard"); 
        
        if (environment(me)->query("short") == "玄岳门")
        {
                me->add("contribution", 50);
                me->add("combat_exp", random(220) + 120);
                me->add("potential", random(100) + 80);
                if (me->query("potential") > me->query_potential_limit())
                        me->set("potential", me->query_potential_limit()); 
                
                tell_room(environment(me), me->query("name") + "在武当山门值守期已满。\n");
                tell_object(me, "你在武当山门值守期已满。\n");
        } else 
        {
                tell_room(environment(me), me->query("name") + "在武当山门值守走开，失败。\n");
                tell_object(me, "你在武当山门值守走开，失败。\n");
        }
}

void die()
{
        object *me;
        int i;

        me = all_inventory(environment());
        
        for (i = 0; i < sizeof(me); i ++)
                me[i]->delete_temp("in_guard"); 

        ::die();
}