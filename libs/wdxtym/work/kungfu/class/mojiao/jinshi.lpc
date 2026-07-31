// This program is a part of NITAN MudLIB

#include <ansi.h>
#include "mojiao.h"

inherit NPC;
inherit F_MASTER;
inherit F_QUESTER;

void create()
{
        set_name("金狮", ({"jin shi", "jin", "shi"}));
        set("title", "魔教长老");
        set("gender", "男性");
        set("age", 52);
        set("shen_type", -1);
        set("long", "魔教四大长老之首，此人三尺多高，三尺长的袍子穿在他身上，已经拖下了地。\n"
                    "他的胡子比这件金袍更长，他的剑比胡子还长。背后却背着柄四尺长的剑，用\n"
                    "黄金铸成的剑鞘已拖在地上，这个人看起来实在也不像是个人。\n");
        set("attitude", "peaceful");

        set("per", 21);
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);

        set("qi", 20000);
        set("max_qi", 20000);
        set("jing", 10000);
        set("max_jing", 10000);
        set("neili", 130000);
        set("max_neili", 130000);
        set("jiali", 3000);

        set("combat_exp", 150000000);
        set("score", 0);

        set_skill("force", 280);
        set_skill("moshen-xinfa", 280);
        set_skill("chiyou-kuangzhanjue", 250);
        set_skill("dodge", 280);
        set_skill("moshen-bufa", 280);
        set_skill("jiutian-xiaoyaobu", 250);
        set_skill("strike", 280);
        set_skill("moshen-zhangfa", 280);
        set_skill("cuff", 280);
        set_skill("moshen-quanfa", 280);
        set_skill("sword", 280);
        set_skill("moshen-jianfa", 280);
        set_skill("jinshi-kuangjian", 250);
        set_skill("blade", 280);
        set_skill("moshen-daofa", 280);
        set_skill("parry", 250);
        set_skill("literate", 210);
        set_skill("medical", 200);
        set_skill("mojiao-medical", 200);

        map_skill("force", "chiyou-kuangzhanjue");
        map_skill("dodge", "jiutian-xiaoyaobu");
        map_skill("strike", "moshen-zhangfa");
        map_skill("cuff", "moshen-quanfa");
        map_skill("sword", "jinshi-kuangjian");
        map_skill("blade", "moshen-daofa");
        map_skill("parry", "jinshi-kuangjian");

        prepare_skill("strike", "moshen-zhangfa");
        
        create_family("魔教", 40, "长老");
  
        set("chat_chance_combat", 120); 
        set("chat_msg_combat", ({
                (: perform_action, "sword.kuang" :), 
                (: exert_function, "recover" :),
        }) );

        set_temp("apply/attack", 280);
        set_temp("apply/damage", 280);
        set_temp("apply/unarmed_damage", 280);
        set_temp("apply/armor", 280);
                        
        set("master_ob", 5);
	setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/changjian")->wield();
        add_money("silver",70);
}

void attempt_apprentice(object ob)
{
        if (! permit_recruit(ob))  return;

        if ((int)ob->query_skill("moshen-xinfa", 1) < 120) 
        {
                command("say 本教的内功心法你还没练好，还要多下苦功才行！");
                return;
        }
        
        command("recruit " + ob->query("id"));
}
/*
int accept_ask(object me, string topic)
{
        switch (topic)
        {
        case "历练" :
        case "历炼" :
        case "锻炼" :
                return QUEST_D->accept_ask(this_object(), me, topic);
                break;

        case "狂剑" :
                return MASTER_D->teach_pfm(me, this_object(),
                        ([ "perform" : "can_perform/jinshi-kuangjian/kuang",
                           "name"    : "狂剑",
                           "sk1"     : "jinshi-kuangjian",
                           "lv1"     : 200,
                           "dodge"   : 200,
                           "gongxian": 1000,
                           "shen"    : -50000, ]));
                break;

        default:
                return 0;
        }
}*/