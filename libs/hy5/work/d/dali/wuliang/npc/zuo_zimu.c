// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;


inherit NPC;
inherit F_MASTER;


mixed ask_me();

void create()
{
        set_name("左子穆", ({ "zuo zimu", "zuo", "zimu"}));
        set("gender", "男性");
        set("title", "无量剑派东宗掌门");
        set("age", 54);
        set("long", @LONG
这就是无量剑派东宗掌门左子穆，只见他五十
多岁年纪，身着青衫，作儒生打扮。他腰间佩
有一柄长剑，想必剑法着实了得。
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 15800);
        set("max_qi", 15800);
        set("jing", 15000);
        set("max_jing", 15000);
        set("neili", 17000);
        set("max_neili", 17000);
        set("jiali", 120);
        set("level", 20);
        set("combat_exp", 5000000);

        set_skill("force", 280);
        set_skill("xiaowuxiang", 280);
        // set_skill("dahai-wuliang", 180);
        set_skill("dodge", 280);
        set_skill("feiyan-zoubi", 280);
        set_skill("sword", 280);
        set_skill("wuliang-jian", 380);
        set_skill("strike", 280);
        set_skill("liuyang-zhang", 280);
        // set_skill("unarmed", 160);
        // set_skill("liuhe-quan", 160);
        // set_skill("claw", 160);
        // set_skill("da-qinna", 160);
        set_skill("parry", 280);
        set_skill("martial-cognize", 360);
        set_skill("literate", 360);
set("pubmaster",1);
        map_skill("dodge", "feiyan-zoubi");
        map_skill("force", "xiaowuxiang");
        map_skill("sword", "wuliang-jian");
        map_skill("parry", "wuliang-jian");
        map_skill("strike", "liuyang-zhang");

        prepare_skill("strike", "liuyang-zhang");

        set("inquiry", ([
                "虚竹子"   : "他是我们灵鹫宫新的主公，我们全部听他号令。",
                "虚竹"     : "他是我们灵鹫宫新的主公，我们全部听他号令。",
        ]));

        create_family("无量剑派", 22, "东宗掌门");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.qian" :),
                (: exert_function, "powerup" :),
                (: exert_function, "recover" :),
        }) );

        set("master_ob",3);
	setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

int recognize_apprentice(object ob, string skill)
{
        if (ob->query("family/family_name") != "灵鹫宫"  && ob->query("family/family_name") != "逍遥派")
        {
                command("say 你我素不相识，何谈得上“指教”二字？");
                return 0;
        }



        if (! ob->query_temp("can_learn/zuozimu"))
        {
                command("say 既然阁下是主公身旁的人，我也就恭敬不如从命了。");
                ob->set_temp("can_learn/zuozimu", 1);
        }
        return 1;
}




void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "灵鹫宫")
{
        command("nod2");
        command("say 那你以后就跟着我好了。");
        command("recruit " + ob->query("id"));
}
}


/*
void unconcious()
{
        die();
}
*/
