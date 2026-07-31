// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;

#include <ansi.h>

int wieldblade();
void create()
{
    set_name("萧秋雨", ({ "killer", "xiao qiuyu"}) );
    set("title",  HIC"断肠剑客"NOR);
    set("gender", "男性" );
    set("class","shenshui");
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
一个个很斯文，很秀气的文弱书生，一张白白净净的脸上，总是带着微笑。\n");

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
        (: perform_action, "dodge.lianhuanbu" :),
//                (: wieldblade  :),
        (: perform_action, "sword.shuanglengcanxia" :),
             }) );
    set("combat_exp", 5000000);
    set("chat_chance", 1);
    set("chat_msg", ({
                "萧秋雨长叹道：“秋风秋雨愁煞人，所以每到杀人时，我总是难免要发愁的。”\n",
            }) ); 

 set_skill("unarmed", 150);
    set_skill("sword", 150);
    set_skill("force", 180);
    set_skill("parry", 140);
    set_skill("dodge", 140);
    set_skill("literate", 140);
    set_skill("move",200);
    set_skill("charm",280);
    set_skill("nine-moon-spirit", 200); 
    set_skill("nine-moon-steps", 180);
    set_skill("nine-moon-claw", 200);
    set_skill("nine-moon-force", 150);
    set_skill("nine-moon-sword", 200); 
    map_skill("dodge", "nine-moon-steps");
    map_skill("unarmed", "nine-moon-claw");
    map_skill("force", "nine-moon-force");
    map_skill("sword", "nine-moon-sword");  
    set_temp("apply/dodge", 100);
        set_temp("apply/parry", 100); 

   setup();
   carry_object("/d/wudang/obj/sword2")->wield();
   carry_object("/d/laowu/npc/obj/raincoat")->wear();
 
} 
