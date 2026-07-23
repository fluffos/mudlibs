 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
    set_name("言青衣", ({ "master yan", "master"}) );
    set("nickname", GRN "销魂"NOR);
    set("gender", "女性" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    set("age", 60);
    set("ill_boss",5);
    set("per", 25);
    set("str", 88);
    set("int",30);
    set("attitude","friendly");
            set("max_jing",16000);
        set("max_qi",16000);
    set("max_neili", 8000);
    set("neili", 8000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    set("no_busy", 8);
            set("neili",16000);
        set("max_neili",16000);
        set_skill("literate", 100);
	set_skill("sword",330);
	set_skill("softsword",350);
        set_skill("cloudforce",320);
        set_skill("shadowsteps",320);
	map_skill("force", "cloudforce");
	map_skill("parry","softsword");
        map_skill("sword","softsword");
        map_skill("dodge","shadowsteps");
        map_skill("dodge","shadowsteps"); 
    set("long", "
小言销魂本来就是名副其实的，可惜那已是多年前的事。
现在言青衣已经又老又丑，人见人跑。只是她那一身功夫依然无人敢怀疑。\n");
    create_family("财神庙", 6, "当家");
    set("rank_nogen",1);
    set("ranks",({"脚夫","伙计","信差","趟子手","执旗手","镖师","镖头",
                      "副总镖头","总镖头",HIW"特使"NOR,
                      RED"令主"NOR,HIY"大当家"NOR}));
    set("rank_levels",({ 32000,64000,128000,256000,512000,
                             1024000,1536000,2304000,3456000,
                             5187000,26244000 })); 

    set("combat_exp", 10000000);



    set_skill("parry",200);
    set_skill("dodge", 120);
    set_skill("force", 160);
    set_skill("literate", 150);
    set_skill("unarmed",160);
    set_skill("staff",200);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);      
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.bajian" :),
                (: perform_action, "sword.yixiao" :),
                (: perform_action, "dodge.lianhuanjiao" :),
        }) );





   setup();
   carry_object(__DIR__"obj/junkstaff")->wield();
   carry_object("/clone/misc/cloth")->wear(); 
   add_money("gold", 1);
} 
