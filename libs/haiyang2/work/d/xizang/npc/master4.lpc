 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_MASTER;
#include <ansi.h> 
void create()
{
    set_name("胡金袖", ({ "master hu", "master"}) );
    set("nickname", HIY "身轻如燕"NOR);
    set("gender", "女性" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 5);
    set("age", 34);
    set("per", 35);
    set("str", 25);
    set("ill_boss",5);
    set("int",30);
    set("attitude","friendly");
    set("max_neili", 800);
    set("neili", 800);
    
    set("long", "
她身上宽大的袖子飘逸、柔软、华美，袖口绣着金边，是名家用金线绣出的牡丹。\n袖中伸出的一双玉手，修长、圆润、十指纤纤宛如白玉雕成。\n");
    create_family("财神庙", 12, "当家");
    set("rank_nogen",1);

    set("combat_exp", 3500000);
        set("neili",16000);
        set("max_neili",16000);
        set("max_jing",16000);
        set("max_qi",16000);
        set("chat_chance", 1);
    set("chat_msg", ({
                "胡金袖掩口偷笑：狼牙怎麽会在老卜那，狼牙当然是长在狼嘴里啦．．．\n",
            }) ); 
    set_skill("move", 220);
    set_skill("parry",100);
    set_skill("dodge", 220);
    set_skill("force", 100);
    set_skill("literate", 140);
    set_skill("unarmed",100);
    set_skill("sword",120);

        set_skill("unarmed", 100);
        set_skill("sword", 100);
        set_skill("throwing", 100);
        set_skill("force", 90);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("literate", 100);
  //      set_skill("perception", 100);

        set_skill("nine-moon-steps", 350);
        set_skill("nine-moon-claw", 350);
        set_skill("nine-moon-force", 300);
        set_skill("nine-moon-sword", 300);

        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");

        set_temp("apply/defense", 100);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 500);
        set_temp("apply/damage", 600);
       set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.suicidal" :),
        }) );



   setup();
   carry_object(__DIR__"obj/thin_sword")->wield();
   carry_object("/clone/misc/cloth")->wear(); 
} 
