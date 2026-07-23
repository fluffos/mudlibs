#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("山寨喽罗",({"bandit"}));
        set("title",YEL"龙虎寨"NOR); 
        set("long","一个身穿黑衣，拿着明晃晃钢刀的小土匪。\n");
        set("gender","男性");
        set("age",32);
        set("group","longhuzhai");      
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",35);
        
        set_skill("unarmed",120);
        set_skill("dodge",150);
        set_skill("parry",160);
        set_skill("force",180);
        set_skill("move",200); 
        set_skill("blade",220); 
        
        set("neili",500);
        set("max_neili",500);
        set("force_factor",90);
        set("max_atman",200);
        set("atman",200);
        set("max_mana",200);
        set("mana",200);
        
        set("combat_exp",1034101);  
        set("attitude", "aggressive");
                
        set("death_msg",CYN"\n$N叫道：“早知道。。就不当土匪了。。”\n"NOR);    
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([
                10: "山寨喽罗叫道：“送上门的肥羊，弟兄们并肩上呀。”\n",
                15: "山寨喽罗叫道：“大王，大王在哪里？顶不住了。”\n",
        ]) );           
        set("chat_chance_combat", 100);
/*        set("chat_msg_combat", ({
             (: auto_smart_fight(20) :),
        }) );*/
        set("chat_chance",1);
        set("chat_msg",({ 
        }) );                   
        
//           CHAR_D->setup();_char(this_object());
//        auto_npc_setup();("wang",150,130,1,"/obj/weapon/","fighter_w","bat-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
        carry_object("/clone/weapon/gangdao")->wield();    
    
}        
