#include <ansi.h>
inherit NPC; 
void create()
{
        set_name("老家人",({"lao jiaren","jiaren"}));
        set("title","薛家庄");
        set("long","一个白发苍苍的老家人，身子佝偻。他幼时本是薛斌的书童，在薛家已近六十年。
少年时，他也是个精壮的小伙子，也舞得起三十斤重的铁斧，也杀过些绿林好汉。
但现在，他不但背已驼，腰已弯，身上的肌肉已松弛，而且还得了气喘病，走几
步路都会喘起来。\n");
        set("gender","男性");
        set("age",32);
                set("ill_boss",5);
        set("int",22);
        set("cor",30);
        set("cps",20);
        set("str",100);
        
        set_skill("unarmed",300);
        set_skill("dodge",300);
        
        set("neili",1500);
        set("max_neili",1500);
        set("force_factor",120);
        set("max_atman",500);
        set("atman",500);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",2000000);  
        set("attitude", "friendly");
        
        
       // set("death_msg",CYN"\n$N悔恨地说：“我的剑。。还是。。。拔得。。太。。慢。。”\n"NOR);          
        set("nb_chat_chance", 100);
        set("nb_chat_msg_combat", ([ 
        ]) );           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
       //      (: auto_smart_fight(20) :),
        }) );
       /* set("chat_chance",1);
        set("chat_msg",({
                "薛大汉击掌唱道：：“九月十五月当头，月当头兮血可流，流不尽的英雄泪，杀不尽的仇人
头……”\n",
        }) );                   */
        
       // auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","lianxin-blade",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();    
    
}      
