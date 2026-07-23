// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;


inherit NPC;
inherit F_MASTER;

mixed ask_me();

void create()
{
        set_name("卓不凡", ({ "zhuo bufan", "zhuo", "bufan"}));
        set("gender", "男性");
        set("title", "一字慧剑门门主");
        set("nickname", HIY "剑神" NOR);
        set("age", 37);
        set("long", @LONG
三十三年前，一字慧剑门满门师徒给童姥杀得
精光，当时卓不凡不在福建，幸免于难，从此
再也不敢回去，逃到长白山中荒僻极寒之地苦
研剑法，无意中得了前辈高手遗下来的一部剑
经，勤练剑法三十余年，终于剑术大成，自信
天下无敌。
LONG );
        set("attitude", "peaceful");
        set("str", 30);
        set("int", 30);
        set("con", 30);
        set("dex", 30);
    
        set("qi", 9500);
        set("max_qi", 9500);
        set("jing", 9200);
        set("max_jing", 9200);
        set("neili", 9800);
        set("max_neili", 9800);
        set("jiali", 150);
        set("level", 30);
        set("combat_exp", 2200000);
set("pubmaster",1);
        set_skill("force", 220);
        set_skill("bahuang-gong", 220);
        set_skill("sword", 240);
        set_skill("zhougong-jian", 240);
        set_skill("dodge", 220);
        set_skill("feiyan-zoubi", 220);
        set_skill("strike", 180);
        set_skill("liuyang-zhang", 180);
        set_skill("parry", 220);
        set_skill("martial-cognize", 220);
        set_skill("literate", 180);

        map_skill("force", "bahuang-gong");
        map_skill("sword", "zhougong-jian");
        map_skill("dodge", "feiyan-zoubi");
        map_skill("parry", "zhougong-jian");
        map_skill("strike", "liuyang-zhang");

        prepare_skill("strike", "liuyang-zhang");

        set("inquiry", ([
                "周公剑"   : "此乃天下第一剑法。",
                "剑神"     : "论空手，自然是我主公虚竹子第一。但若是论剑法嘛，还得是我。",
                "天山童姥" : "她杀尽我一字慧剑门满门师徒，幸亏她死得早！",
                "虚竹"     : "他是我们灵鹫宫新的主公，我们全部听他号令。",
                "虚竹子"   : "他是我们灵鹫宫新的主公，我们全部听他号令。",
                "剑法"     : "我的周公剑天下无双，除了主公，没第二人能够敌过。",
        ]));

        create_family("一字慧剑门", 3, "门主");

        set("chat_chance_combat", 120);
        set("chat_msg_combat", ({
                (: perform_action, "sword.mang" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
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
                command("killair");
                command("say 你是什么东西，竟想习我精妙的剑法！");
                return 0;
        }




        if (skill == "sword" && ob->query_skill("sword", 1) > 179)
        {
                command("hmm");
                command("say 够了，剩下的剑法自己去研究。");
                return 0;
        }

        if (! ob->query_temp("can_learn/zhuobufan"))
        {
                command("nod2");
                command("say 既然你感兴趣，又是主公的弟子，我就教你这套周公剑。");
                ob->set_temp("can_learn/zhuobufan", 1);
        }
        return 1;
}


void attempt_apprentice(object ob)
{
if (ob->query("family/family_name") == "灵鹫宫")
{
        command("smile");
        command("say 甚好！甚好！");
        command("say 我一字慧剑门门下无徒，今日老夫便收下你。");
        command("recruit " + ob->query("id"));
}
}


/*
void unconcious()
{
        die();
}
*/
