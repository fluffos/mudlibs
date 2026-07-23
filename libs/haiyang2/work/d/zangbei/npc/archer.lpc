#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("山寨弓箭手",({"archer"}));
        set("title",YEL"龙虎寨"NOR); 
        set("long","一个身穿黑衣，拿着一把长弓的小土匪。\n");
        set("gender","男性");
        set("age",32);
        set("group","longhuzhai");      
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",35);
        
        set("neili",500);
        set("max_neili",500);
        set("force_factor",90);
        set("max_atman",200);
        set("atman",200);
        set("max_mana",200);
        set("mana",200);
        
        set("combat_exp",1000000);  
        set("attitude", "aggressive");
                
        set("death_msg",CYN"\n$N叫道：“早知道。。就不当土匪了。。”\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: "山寨喽罗叫道：“送上门的肥羊，弟兄们并肩上呀。”\n",
                15: "山寨喽罗叫道：“大王，大王在哪里？顶不住了。”\n",
        ]) );           

        set("chat_chance",1);
        set("chat_msg",({ 
        }) );                   
        
         
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}    
