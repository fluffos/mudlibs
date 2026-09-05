#include <ansi.h>
inherit NPC;
string ask_me(object who);
void create()
{
        set_name("蒙面人", ({ "mengmian ren", "ren","mengmian"}) );
        set("gender", "男性" );
        set("shen_type", -1);
        set("age", 40);
        set("str", 25);
        set("cor", 25);
        set("cps", 25);
        set("int", 25);
        set("long",
                "这是个高大强壮的男子，不过总是蒙着脸。\n" );
        set("combat_exp", 35000);
        set("attitude", "heroism");
        
        set_skill("blade", 70);
        set_skill("dodge", 60);
        set_skill("unarmed", 40);
        set_skill("parry", 60);

        set_temp("apply/attack",  50);
        set_temp("apply/defense", 50);
        set_temp("apply/damage",  20);
        set("pursuer", 1);
        set("attitude", "aggressive");
        set("vendetta/authority", 1);
   
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :)
        }) );
        set("bellicosity", 10000);
        set("combat_exp", 60000);
    
        set("revealed", 1);
        
        setup(); 
      carry_object("/d/huashan/npc/obj/gangdao")->wield();
        carry_object("/clone/misc/cloth")->wear();
       add_money("gold",2);
}
