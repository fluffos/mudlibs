#include <ansi.h>
#include <command.h> 
inherit NPC;  
void create()
{ 
        set_name("衣衫惨绿的中年人",({"middle age man","man"}));
        set("long", "衣衫惨绿的中年人，手持一把短剑。\n");
        set("age",37);
        set("combat_exp", 5000000);
                
        set("max_atman", 1000);
        set("atman", 1000);
        set("max_mana", 1000);
        set("mana", 1000);
        set("max_force",1500);
        set("force",1500);
        set("force_factor",100);
        
        set("pursuer", 1);
        set("parrot_killer",1);
        set("cor", 40);
        set("cps", 40);
        set("agi",40);
        set("fle",40);
        
        set("resistance/gin",30);
        set("resistance/kee",30);
        set("resistance/sen",30);
        
//      setting up special NPC function: healer, defense, zombie-killer
//      defense_type: 1. xiaohun-sword; 2.xiaohun-whip;3 yue-strike;4 lingxi-zhi;
        
//      set("defense_type",random(2)+1);        
//      set("zombie-killer",1);
//      set("officer-killer",1);
//      set("dungeon_npc","check");
        set("death_msg",CYN"\n$N说：完了，攒的银子再多有什么用。。 \n"NOR); 
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10:     "\n中年人说：我们什么事都不管，只管杀人！！！\n",
        ]) ); 

        set_skill("move",1000);
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object("/clone/weapon/gangjian")->wield();
}    
 
void die() {
        
        object me, ob, owner;
        ob=this_object();
        
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        
        if (me)
        if(me->query("parrot/三爷刺客")) {
                me->set("parrot/三爷刺客",1);
        }
        ::die();
}   
