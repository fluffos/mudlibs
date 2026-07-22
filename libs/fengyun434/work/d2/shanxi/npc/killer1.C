// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;

#include <ansi.h>

int wieldblade();
void create()
{
    set_name("柳余恨", ({ "killer", "liu yuhen"}) );
    set("title",  GRN"玉面郎君"NOR);
    set("gender", "男性" );
    set("class","quanli");
    set("reward_npc", 1);
    set("difficulty", 10);
    
    set("age", 35);
    set("per", 15);
    set("agi", 300);
    set("str", 50);
    set("int",30);
    set("ill_boss",5);
    //set("attitude","friendly");
    set("max_force", 3000);
    set("force", 3000);
    set("atman", 5400);
    set("max_atman", 5400); 
    set("mana", 5000);
    set("max_mana", 5000);
    
    set("long", "
这张脸左面已被人削去了半边，伤口现在已干瘪收缩。把他的鼻子和眼睛都
歪歪斜斜的扯了过来，不是一个鼻子，是半个，也不是一双眼睛，是一只。
他的右眼已只剩下了一个又黑又深的洞，额角被人用刀锋划了个大“十”字。\n");

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.changmengwuchen" :),
//                (: wieldblade  :),
        (: perform_action, "unarmed.pofuchenzhou" :),
             }) );
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "柳余恨冷冷道：“我此来但求一死而已。”\n",
            }) ); 


    set_skill("dagger", 150);
    set_skill("move", 160);
    set_skill("parry",120);
    set_skill("dodge", 120);
    set_skill("force", 180);
    set_skill("literate", 100);
    set_skill("unarmed",220);
  //  set_skill("blade",200);

  //  set_skill("xiruo-blade",180);
    set_skill("liumang-strike",220);
    set_skill("wuchen-steps",120);
    set_skill("yuping-dagger",200);
    set_skill("wuchenforce",200);

  //  map_skill("blade", "xiruo-blade");
    map_skill("dodge", "wuchen-steps");
    map_skill("move", "wuchen-steps");
    map_skill("force", "wuchenforce");
    map_skill("unarmed", "liumang-strike");

    map_skill("dagger","yuping-dagger");
    map_skill("parry","yuping-dagger");


   setup();
   //carry_object(__DIR__"obj/dagger")->wield();
   carry_object("/d/laowu/npc/obj/raincoat")->wear();
 
} 
