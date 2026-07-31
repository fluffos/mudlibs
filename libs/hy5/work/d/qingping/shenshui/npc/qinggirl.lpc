 // thousand_hand.c
#include <ansi.h> 
inherit NPC;
void create()
{
        set_name("青衣小鬟" , ({ "girl", "qing yi" }) );
        set("long", "一位十几岁的丫头，正在忙碌着。\n");
        set("attitude", "friendly");
        set("class","shenshui");
        set("max_jing", 500);
        set("max_qi", 500);
        set("max_jing", 500);
        set_skill("unarmed",10);
        set_skill("nine-moon-claw",10);
        map_skill("unarmed","nine-moon-claw");
        set("age", 15);
        set("gender", "女性" );
        set("combat_exp", 5000);
        set_skill("dodge", 50+random(100));
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
                (: perform_action, "unarmed.suicidal" :),
        }) );
        
        
        setup();
        carry_object(__DIR__"obj/cloth2")->wear();
}      
