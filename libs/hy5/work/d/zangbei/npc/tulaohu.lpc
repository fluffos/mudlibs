#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("屠老虎",({"tu laohu","tu","laohu"}));
        set("title",YEL"龙虎寨 老三"NOR);
        set("long","
屠老虎的头脑本来就比一只老虎聪明不了多少，尤其在喝酒之后，他简直比老
虎还笨，也比老虎还要凶。他最凶的是拳头。据说他一拳可以打死只活老虎，
这虽然没人真的看过，却没有人敢怀疑。因为他一拳打死的人已不少。\n");
        set("gender","男性");
        set("age",32);
        set("group","longhuzhai");
         set("reward_npc", 1);
        set("difficulty", 1);
                
        set("int",22);
        set("cor",30);
        set("cps",100);
        set("str",40+random(50));
        
        set_skill("unarmed",300);
        set_skill("dodge",120);
        set_skill("parry",160);
        set_skill("move",150); 
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",10);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4500000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        set("step_less",2);
        
        
        set("death_msg",CYN"\n$N那一百多斤重的身子，被打得飞了出去。飞出去四丈外，重重地撞
在墙上，再沿着墙滑下来。\n"NOR);         
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
           set("chat_chance_combat", 100);
         set("chat_msg_combat", ({

            (: perform_action, "unarmed.paoxiao" :),
            }) ); 
        set("chat_chance",1);
        set("chat_msg",({
                "屠老虎狞笑道：“你若真的想找个地方睡觉，就找错地方了，这里没有床，只有棺材。”\n",
        }) );                   
        
//        auto_npc_setup();("wang",200,200,0,"/obj/weapon/","fighter_w","dragonstrike-jg",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/seed");    
    
}   
void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") )) {    
                if(owner=me->query("possessed")) me = owner;
                if(me->query("wanma/准备杀山贼")) me->set_temp("wanma/屠老虎",1);
        }
        ::die();
}
