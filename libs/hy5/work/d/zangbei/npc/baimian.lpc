#include <ansi.h>
//inherit NPC; 
inherit NPC;
void create()
{
        set_name("白面郎中",({"baimian langzhong","baimian","langzhong"}));
        set("title",YEL"龙虎寨 老二"NOR);
        set("long","
白面郎中是龙虎寨的二当家。他的脸部不很白，也从没做过郎中，不过，绿林
好汉若没有一个响亮的外号，那还成什么绿林好汉，所以他几乎已将自己本来
名字忘了。\n");
        
        set("gender","男性");
        set("group","longhuzhai");
        
        set("age",32);          
        set("int",52);
        set("cor",30);
        set("cps",20);
        set("str",80);
        set("class", "tieflag");

        set("reward_npc", 1);
        set("difficulty", 1);
        
        set_skill("sword",180);
        set_skill("dodge",200);
        set_skill("parry",160);
        set_skill("move",150); 

        set_skill("tie-steps",220); 
        
        map_skill("parry","six-chaos-sword");
        map_skill("sword","six-chaos-sword");
        map_skill("dodge","tie-steps");
        map_skill("move","tie-steps");

        
        set("neili",2500);
        set("max_neili",2500);
        set("force_factor",20);
        set("max_atman",800);
        set("atman",800);
        set("max_mana",500);
        set("mana",500);
        set("combat_exp",2000000);  
        set("attitude", "friendly");
        
        set("resistance/kee",30);
        set("resistance/gin",30);
        set("resistance/sen",30);
        
        set("death_msg",CYN"\n$N说：“善者不来，来者不善啊。”\n"NOR);          
           
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.chansi" :),
        }) ); 

        set("chat_chance",1);
        set("chat_msg",({
                "白面郎中道：“我们这里的人本来就不喜欢打架的。”\n",
        }) );                   
        
//        auto_npc_setup();("wang",200,160,0,"/obj/weapon/","fighter_w","fy-sword",2);
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        carry_object(__DIR__"obj/gsword")->wield();    
    
}  
