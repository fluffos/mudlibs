// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>
inherit NPC;

void create()
{
        set_name("泥潭野老", ({ "nitan yelao", "yelao" }));
        set("gender", "男性");
        set("age", 2100);
        set("title", CYN "武林智者" NOR);
        set("long", sort_msg(
                "传说中的武林前辈，据说此老乃千年前的武林宿耄，现今已千岁高龄。"
                "他笑傲武林数千载，天下的武功，各门各派奇闻轶事，古往今来武林"
                "典故，号称是“无所不知，无所不晓”。一身武功是出神入化，罕逢"
                "敌手，至今数千年未曾与人动手。多年来一直隐居扬州城中评书为生，"
                "每日在此讲述武林典故。\n"));        
        set("combat_exp", 30000000);
        set("shen_type", 0);
        set("max_neili", 500000);
        set("neili", 500000);
        set("max_qi",40000);
        set("max_jing",20000);
        set("max_jingli",20000);
        set("jingli",20000);
        set("per",25);
        set("jiali", 400);
        
        set_skill("force", 500);
        set_skill("unarmed", 500);
        set_skill("dodge", 500);
        set_skill("parry", 500);
        set_skill("jiuyang-shengong",500);

        set("chat_chance", 2);
        set("chat_msg", ({  
                CYN "野老面色一沉，正言道：“大丈夫立世，人品第一，武功的高低倒在其次，\n"
                "若不能行侠仗义，惩恶扬善，当真苟存于天地间了！”\n" NOR
        }));

        set_temp("apply/attack", 50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage", 50);
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob = this_player();

        if (ob->query("slough/inquiry"))
        {
                message_sort(HIC "$N面露微笑，朝$n点头道：你回来啦，"
                             "可曾查到什么没有？查到了就快告诉我（answer <门派>） ！\n" NOR,
                             this_object(), ob);
                add_action("do_answer", "answer");
        }
}

int do_answer(string arg)
{
        return SLOUGH_D->do_answer(this_object(), this_player(), arg);
}

mixed accept_ask(object who, string topic) 
{
        switch (topic)
        {
        case "quest": 
        case "行侠仗义":
        case "惩恶扬善":
                return SLOUGH_D->ask_quest(this_object(),  who); 
        default: 
                return 0;
        }
}

int accept_object(object who, object ob) 
{
        return SLOUGH_D->accept_object(this_object(), who, ob); 
}
