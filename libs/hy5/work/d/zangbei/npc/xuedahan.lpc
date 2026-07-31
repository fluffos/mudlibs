#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("薛大汉",({"xue dahan","xue","dahan"}));
        set("title","绿林好汉");
        set("long","一条身高八尺的彪形大汉，肩膀几乎有平常两个宽，一双蒲扇般的
大手垂下来，几乎已盖过了膝盖，脸上颧骨高耸，生着两道扫帚般
的浓眉，一张大嘴。他身上穿的衣服虽然又脏又破，但一站起，
可是威风凛凛，叫人看着害怕。\n");
        set("gender","男性");
        set("age",32);
                set("reward_npc", 1);
       set("difficulty", 20);
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",40);
        set("no_busy", 9);
                       set("class","knight");
        set_skill("unarmed", 180);
       

        set_skill("axe", 200);
        set_skill("literate", 140);
        set_skill("dodge", 140);
        set_skill("move", 140);
        set_skill("parry", 160);
        set_skill("force", 200);

               

          
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",4000000);  
        set("attitude", "friendly");
        
        
       // set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (:perform_action,"axe.jiuqipoxiao":),
        }) );
        set("chat_chance",1);
        set("chat_msg",({
                "薛大汉击掌唱道：：“九月十五月当头，月当头兮血可流，流不尽的英雄泪，杀不尽的仇头……”\n",
           }) );                   
        

       // auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}     
