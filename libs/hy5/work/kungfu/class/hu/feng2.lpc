// Copyright (C) 2003, by Lonely. All rights reserved.
// This software can not be used, copied, or modified 
// in any form without the written permission from authors.

#include <ansi.h>;

inherit NPC;


string ask_me();

void create()
{
        set_name("凤天南", ({ "feng tiannan", "feng" }));
        set("gender", "男性");
        set("nickname", HIR "五虎断门刀" NOR);

        set("age", 37);
        set("long", @LONG
这人看上去武功盖世。
LONG);
        set("attitude", "peaceful");
        set("str", 56);
        set("int", 38);
        set("con", 31);
        set("dex", 10);
    
        set("qi", 26000);
        set("max_qi", 26000);
        set("jing", 26000);
        set("max_jing", 26000);
        set("neili", 26500);
        set("max_neili", 26500);
        set("jiali", 160);
        set("level", 40);
        set("combat_exp", 8000000);
        set("vendetta/authority",1);
        set_skill("force", 290);
        set_skill("lengyue-shengong", 290);
        set_skill("blade", 460);
        set_skill("baisheng-daofa", 460);
        set_skill("hujia-daofa", 290);
        set_skill("zileidao", 290);
        set_skill("dodge", 290);
        set_skill("sixiang-bufa", 290);
        set_skill("parry", 290);
        set_skill("strike", 290);
        set_skill("tianchang-strike", 290);
        set_skill("cuff", 290);
        set_skill("hujia-quan", 290);
        set_skill("throwing", 200);
        set_skill("mantian-xing", 200);
        set_skill("literate", 290);
        set_skill("martial-cognize", 240);

        map_skill("force", "lengyue-shengong");
        map_skill("blade", "zileidao");
        map_skill("dodge", "sixiang-bufa");
        map_skill("parry", "baisheng-daofa");
        map_skill("strike", "tianchang-strike");
        map_skill("cuff", "hujia-quan");
        //map_skill("throwing", "mantian-xing");

        prepare_skill("strike", "tianchang-strike");
        prepare_skill("cuff",   "hujia-quan");

        create_family("五虎门", 1, "掌门");



        set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: perform_action, "blade.huanying" :),
                 (: perform_action, "blade.posui" :),
                (: perform_action, "blade.tulong" :),                 	
                (: perform_action, "cuff.kuai" :),
                (: perform_action, "strike.huang" :),
                (: perform_action, "dodge.fei" :),
                (: exert_function, "recover" :),
                (: exert_function, "powerup" :),
        }));
	set_temp("apply/attack",100);
	set_temp("apply/defense",100);
	set_temp("apply/armor",800);
	set_temp("apply/damage",800);        

        set("master_ob",5);
	setup();
        carry_object("/clone/weapon/gangdao")->wield();
        carry_object("/clone/cloth/cloth")->wear();
}

