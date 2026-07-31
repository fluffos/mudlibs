// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("狄云", ({ "di yun", "di","yun" }));
        set("long", 
                "他就是"+HIR"血刀门"NOR+"弟子狄云。\n"
                "他今年看起来倒满和蔼的。\n");
        set("gender", "男性");
        set("age", 30);
        set("attitude", "peaceful");
        set("shen_type", 1);
        set("str", 25);
        set("int", 25);
        set("con", 25);
        set("dex", 25);
        
        set("max_qi", 3500);
        set("max_jing", 1500);
        set("neili", 5000);
        set("max_neili", 5000);
        set("jiali", 50);
        set("level", 40);
        set("combat_exp", 5000000);
        set("score", 40000);
        
        set_skill("dodge", 400);
        set_skill("parry", 400);
        set_skill("hand", 400);
        set_skill("mizong-neigong", 400);
        set_skill("dashou-yin", 400);
        set_skill("unarmed", 400);
        set_skill("blade", 400);
        set_skill("literate", 400);
        set_skill("xuehai-mogong", 400);
        set_skill("xuedao-daofa", 400);
        set_skill("force", 400);
        set_skill("shenkong-xing", 400);
        set_skill("cuff", 400);
        set_skill("yujiamu-quan", 400);
        set_skill("sword", 400);
        set_skill("mingwang-jian", 440);        
        set_skill("liancheng-jianfa", 400);
        set_skill("shenzhaojing", 400);
                
        map_skill("unarmed", "shenjingzhao");
        map_skill("cuff", "yujiamu-quan");
        map_skill("force", "shenzhaojing");
        map_skill("blade", "xuedao-daofa");
        map_skill("parry", "xuedao-daofa");
        map_skill("dodge", "shenkong-xing");
        map_skill("sword", "liancheng-jianfa");

        create_family("血刀门", 6, "弟子");

        setup();
        carry_object("/clone/weapon/gangjian")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

void attempt_apprentice(object ob)
{
        if ((int)ob->query("shen")  < 100000) 
        {
                command("sigh");
                command("say 我已经封门不收弟子了，你请回吧。");
                return;
        }
        if ((int)ob->query_skill("xuehai-mogong", 1) < 120) {
                command("say 练血刀刀法最重内功心法。"); 
                command("say " + RANK_D->query_respect(ob) + 
                        "是否还应该在血海魔功上多下点功夫？");
                return;

        }
        if ((int)ob->query_skill("lamaism", 1) < 100) {
                command("say 入我血刀门，修习密宗心法是首要的。");
                command("say 这位" + RANK_D->query_respect(ob) +


                        "是否还应该多多钻研本门的心法？");
                return;
        }
        
        command("say 好吧，看你还是个人才，血刀门看来得靠你了。");
        command("recruit " + ob->query("id"));
}

int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "历练" :
        case "历炼" :
        case "锻炼" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "quest" :
                return DEFEND_D->ask_quest(this_object(), me); 
                break;
        
        case "finish" : 
                return DEFEND_D->ask_reward(this_object(), me); 
                break;
        
        case "无影神拳" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenzhaojing/ying",
                           "name"    : "无影神拳",
                           "sk1"     : "shenzhaojing",
                           "lv1"     : 100,
                           "sk2"     : "unarmed",
                           "lv2"     : 100,                           
                           "gongxian": 800, ]));
                break;

        case "无影拳舞" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/shenzhaojing/wu",
                           "name"    : "无影拳舞",
                           "sk1"     : "shenzhaojing",
                           "lv1"     : 120,
                           "sk2"     : "unarmed",
                           "lv2"     : 120,
                           "gongxian": 800, ]));
                break;

        case "耳光式" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liancheng-jianfa/erguang",
                           "name"    : "耳光式",
                           "sk1"     : "liancheng-jianfa", 
                           "lv1"     : 120,
                           "sk2"     : "sword",
                           "lv2"     : 120,
                           "gongxian": 600, ]));
                break;

        case "刺肩式" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liancheng-jianfa/cijian",
                           "name"    : "刺肩式",
                           "sk1"     : "liancheng-jianfa", 
                           "lv1"     : 120,
                           "sk2"     : "sword",
                           "lv2"     : 120,
                           "gongxian": 800, ]));
                break;
                
        case "去剑势" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/liancheng-jianfa/qujian",
                           "name"    : "去剑势",
                           "sk1"     : "liancheng-jianfa", 
                           "lv1"     : 120,
                           "sk2"     : "sword",
                           "lv2"     : 120,
                           "gongxian": 600, ]));
                break;
                                                                                
        default:
                return 0;
        }
}
