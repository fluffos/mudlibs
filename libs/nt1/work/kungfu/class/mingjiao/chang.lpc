// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// chang.c 常遇春

#include <ansi.h>
inherit NPC;

string ask_me();
void create()
{
        set_name("常遇春", ({ "chang yuchun","chang","yuchun" }) );
        set("title", "明教巨木旗弟子");
        set("gender", "男性");
        set("age",34);
        set("long","他身材高大，勇猛过人。\n");
        set("str", 24);
        set("int", 27);
        set("con", 23);
        set("dex", 20);
        set("per", 20);
        set("shen_type", 1);
        set("max_qi",700);
        set("max_jing",600);
        set("neili",600);
        set("max_neili",600);
        set("jiali",20);        
        set("eff_jingli",400);        
        set("combat_exp", 190000);
        set("level", 10);

        set_skill("unarmed",60);
        set_skill("force",60);
        set_skill("dodge",60);
        set_skill("parry",60);  
        set_skill("blade",60);  

        set_skill("changquan", 60);
        map_skill("parry", "changquan");
        map_skill("unarmed","changquan");
        prepare_skill("cuff", "changquan"); 

        set("inquiry", 
        ([
                "守卫" : (: ask_me :),
        ]));
        
        setup();
        create_family("明教", 38, "弟子");
        carry_object("/d/mingjiao/obj/black-cloth")->wear();
        carry_object("/clone/weapon/blade")->wield();
}

void attempt_apprentice(object ob)
{     
        command("say 呵呵，我武功低微，可不敢收徒啊。");
        command("say 这位"+RANK_D->query_respect(ob)+"还是请回吧。");
        return;
}

void init()
{
        ::init();
        add_action("do_task","task");
}

string ask_me()
{
        object me, ob, ling;
        me = this_player();
        ob = this_object();
        
        if (me->query("family/family_name")!= "明教")
                return RANK_D->query_respect(ob) + "，你不是本教弟子，此话从何说起？";
                
        if (me->query("combat_exp") < 20000)
                return ("你的武功太差，回去练几年再说吧。");
                
        if (me->query("combat_exp") >= 90000)
                return ("我看你的武功已有相当的功底了，去做别的活吧。\n");
       
        if (me->query_temp("shouwei"))
                return ("你刚才好象还没完成吧？");
                
        ob->set("shouwei_name",ob->query("name"));
        me->set_temp("shouwei", 1);
        ling = new("/d/mingjiao/obj/sw_ling");
        ling->move(me);
        tell_object(me, "常遇春给你一纸守卫书。\n");
        
        return "好吧，你去总坛前厅将信物交给野王兄，由他差遣。";
}

int do_task(string arg)
{
        object ob, me;
        ob = this_player();
        me = this_object();
        
        if (! (arg)) return 0;
        if (! (arg == "ok")) return 0;
        if (! ob->query_temp("shouwei")) return 0;
        if (! ob->query_temp("shouweied")) return 0;
        if (ob->query_temp("shouwei_ok")) 
        {
                if (interactive(ob) &&
                    (int)ob->query_condition("mj_shouwei")) 
                {
                        command("kick" + ob->query("id"));
                        return notify_fail(RED "想偷懒，快给我滚回去。"NOR);
                }          
                ob->add("mingjiao_job", 1);
                command("pat " + ob->query("id"));
                command("say 辛苦你了，" + RANK_D->query_respect(ob) + "，干得好！");
                ob->add("potential", 25 + random(10));
                ob->add("combat_exp", (int)(ob->query_skill("shenghuo-shengong", 1) / 4) + 90);
                me->delete("shouwei_name");
                me->delete_temp("shouwei");
                ob->delete_temp("shouwei");
                ob->delete_temp("shouweied");
                return 1;
        }
        return notify_fail("你这个东西是从哪里来的？\n");
}

