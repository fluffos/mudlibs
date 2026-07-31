#include <ansi.h>
//inherit NPC;
inherit NPC;
void create()
{
        set_name("冲古寺的喇嘛",({"chonggu lama","lama"}));
        set("long", "这是直共寺打扫寺院的喇嘛。\n");
        set("age",30+random(20));
        set("attitude", "friendly");
        set("combat_exp", 1500000);
        set("dungeon_npc","eren");
                
        set("max_mana", 800);
        set("mana", 800);
        set("max_neili",1000);
        set("neili",1000);
        set("force_factor",30+random(20));
        set("class", "lama");
        
        
        set_skill("iron-cloth", 100);
        set_skill("staff", 100);

        set_skill("unarmed", 100);
        set_skill("lamaism", 100);
        set_skill("bloodystrike", 100);
        set_skill("force", 100);

        set_skill("spells",100);
        set_skill("parry",100);


        
        set("cor", 40);
        set("cps", 40);
        set("int",40);
        set("agi",40);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "喇嘛把手里的糌粑捏碎，兴致勃勃地扔到河里去喂鱼。\n",  
        }) );
        set("chat_chance_combat", 100);
         set("chat_msg_combat", ({
            (: perform_action, "unarmed.fefawubian" :),
            }) ); 
/*        set("chat_msg_combat", ({
                (: auto_smart_fight() :),    
        }) );*/
          
//        auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        //set("force_factor",40);
        setup();
        carry_object(__DIR__"obj/lamacloth")->wear();
        
}
