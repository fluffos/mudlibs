#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("邱凤城",({"qiu fengcheng","qiu"}));
        set("title",HIW"银枪公子"NOR);
        set("long","
他年轻、健康、高大、英俊，而且有一种教养良好的气质。他身上穿的是一袭
价值千金的貂裘，手里拿著对光华夺目的银枪。他仰面看著蓝天，痴痴的出神，
眼睛里带著种说不出的悲痛和忧虑。
\n");
        
        set("gender","男性");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("per",40);
        set("difficulty",10);
        set("reward_npc",1);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",7500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N说：“善者不来，来者不善啊。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );      
        set("chat_chance",1);
        set("chat_msg",({
                name()+"坐在那里，痴痴的出神，好像根本没看见你的来到。\n",
        }) );                   
        
        
        setup();
        carry_object(__DIR__"obj/qiucloth")->wear();
        carry_object(__DIR__"obj/qiuspear")->wield();    
    
}      
