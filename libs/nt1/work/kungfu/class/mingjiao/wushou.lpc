// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// wufu.c 殷无寿

#include <ansi.h>
#include "mingjiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

string ask_yin();

void create()
{
        set_name("殷无寿", ({ "yin wushou", "yin", "wushou" }));
        set("title","明教天鹰分舵属下");
        set("age", 46);
	set("long","他是殷家的朴人。\n");
	set("str", 23);
        set("int", 20);
        set("con", 23);
        set("dex", 23);
        set("per", 10);
        set("level", 8);
        set("env/wimpy", 80);
        set("combat_exp", 350000);
        set("attitude", "peaceful");
        
        set_skill("dodge",90);
        set_skill("force", 90);
        set_skill("qingfu-shenfa", 90);
        set_skill("shenghuo-shengong", 90);
        set_skill("liehuo-jian",90);
        set_skill("yingzhua-shou",90);
        set_skill("claw",90); 
        set_skill("parry", 90);        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "piaoyi-shenfa");
        map_skill("claw", "yingzhua-shou");
        map_skill("parry", "yingzhua-shou");
        prepare_skill("claw","yingzhua-shou");
        
        set("inquiry", ([
                "殷无禄"   : (: ask_yin :),
                "yin wulu" : (: ask_yin :),
        ]) );
        create_family("明教", 38, "弟子");     
        setup();
        carry_object("/d/mingjiao/obj/green-cloth")->wear();
}

void attempt_apprentice(object ob)
{        
        if (! permit_recruit(ob))
                return;

        if ((int)ob->query("shen") < 0) 
        {
                command("say " + RANK_D->query_respect(ob) +
                        "有所不知，我平生最恨奸诈之人，你正气太低，我不能让你进入明教半步。");
                return;
        }
        
        command("look " + ob->query("id"));
        command("say 嗯，看你还是个学武的料，我就收下你吧！");
        command("say 多谢明尊敝佑，让我明教又得一良材，为康扶正义，把我明教发扬光大吧。");
        command("recruit " + ob->query("id"));
        ob->set("title","明教天微堂教众");
}

string ask_yin()
{
        object me, ob, where;
        
        me = this_player();
        ob = find_living("yin wulu");
        if (! ob) return "刚有名弟子上来报告，我无禄兄好象被人给杀了。\n";
        
        where = environment(ob);
        if (! where) return "我无禄兄好象巡逻去了，我也不知道他现在在哪里。\n";
        
        return "嗯，无禄兄好象在" + where->query("short") + CYN "一带巡逻。" NOR;        
}
