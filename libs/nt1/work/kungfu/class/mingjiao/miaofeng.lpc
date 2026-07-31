// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.
// miaofeng.c 妙风使

#include <ansi.h>
inherit NPC;
int p();
void create()
{
        set_name("妙风使", ({ "miaofeng shi", "miaofeng", "shi"}) );
        set("title", "明教波斯三使");
        set("gender", "男性");
        set("attitude", "friendly");
        set("age",49);
        set("long", "他身材高大，黄须鹰鼻。\n");
        set("rank_info/respect","使者");
        set("str", 29);
        set("int", 20);
        set("con", 28);
        set("dex", 26);
        set("per", 20);
        set("max_qi",2300);
        set("max_jing",1500);
        set("neili",2600);
        set("max_neili",2600);
        set("jiali",50);
        set("eff_jingli",1500);             
        set("level", 20);
        set("shen_type",0);
        set("combat_exp", 750000);
        
        set_skill("sword", 210);
        set_skill("parry", 210);
        set_skill("force", 210);
        set_skill("cuff", 210);
        set_skill("literate", 270);
        set_skill("dodge", 200);
        set_skill("qingfu-shenfa", 210);
        set_skill("shenghuo-shengong", 210);
        set_skill("shenghuo-ling", 210);
        
        map_skill("force", "shenghuo-shengong");
        map_skill("dodge", "qingyun-shenfa");
        map_skill("sword","shenghuo-ling");
        map_skill("parry", "shenghuo-ling");

        set("coagents", ({ 
                ([ "startroom" : "/d/mingjiao/qinyun", 
                   "id"        : "huiyue shi" ]), 
                ([ "startroom" : "/d/mingjiao/qinyun", 
                   "id"        : "huiyue shi" ]), 
        })); 

        setup();

        carry_object("/clone/book/shenghuo-ling")->wield();
        carry_object("/clone/cloth/cloth")->wear();               
}
