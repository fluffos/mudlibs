 //QCed and Modified by Tie
#include <ansi.h>
inherit NPC;  
inherit F_VENDOR;
int tell_test(); 
void create()
{
        set_name("剑心", ({ "mar", "nomar" }) );
        set("gender", "男性");
        set("title", HIC"沧凉剑客"NOR);
        set("age", 26);
        set("long",
                "一个浪迹天涯，天地为家，满脸沧桑的独行剑客。\n");
        set("combat_exp", 50000000);
        set("attitude", "friendly");
       set("combat_exp", 8000000);
        set("score", 50000); 
        set("class", "taoist"); 
        set("str", 30);
        set("int", 33);
        set("cor", 45);
        set("cps", 30);
        set("spi", 30);
        set("per", 100);
                set("fle",      45); 
        set("force", 4000);
        set("max_neili", 4000);
        set("force_factor", 50);
                set("max_jing",2800);
                set("max_jing",2800); 
                
                
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }));
        
      set_skill("move", 150);

        set_skill("parry", 180);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 180);
        set_skill("sword", 240);
        set_skill("unarmed",100);
        set_skill("music",220);
        set_skill("feixian-steps",520);
        set_skill("feixian-sword",500);

        map_skill("dodge", "feixian-steps");
        map_skill("sword", "feixian-sword");
        map_skill("parry", "feixian-sword");

        map_skill("move","feixian-steps"); 
        set("chat_chance_combat", 90);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
                (: perform_action, "dodge.tianwaifeixian" :),
        }) ); 
        
    setup(); 
            carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
        
} 