#include <ansi.h>
//inherit NPC;
inherit NPC;
void create()
{
        set_name(HIY"替补"NOR,({"guardian"}));
        set("long", "这是蚌普寺打扫寺院的小喇嘛。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30);
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);

        set_skill("unarmed", 100);
        set_skill("lamaism", 100);

        set_skill("force", 100);

        set_skill("spells",100);
        set_skill("parry",100);


        
        

        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "喇嘛把手里的糌粑捏碎，兴致勃勃地扔到河里，顿时鱼儿们就活跃了起来。\n",  
                
        }) );
        set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
            (: perform_action, "unarmed.fefawubian" :),
            }) ); 
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) ); */
          
//        auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        set_name("蚌普寺的喇嘛",({"bangpu lama","lama"}));
        set("force_factor",40+random(50));
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}  
