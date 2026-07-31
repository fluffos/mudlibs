 inherit NPC;
#include <ansi.h>
void smart_fight();
void smart_busy();
void smart_attack(); 
void create()
{
        set_name("拂尘的女子", ({ "housework girl" }) );
        set("gender", "女性");
        set("age", 25);
        set("long",
"一个神水宫的少女,正在打扫屋子。\n"
); 
        set("attitude", "friendly");
        set("score", 2000);
        set("class", "huashan");
        
        set("combat_exp", 2500000);
                
        set("int", 30);
        set("cps", 30);
        set("spi", 30);
        set("fle",50);
        set("resistance/kee",20);
        set("resistance/gin",20);
        set("resistance/sen",20); 
        set("force", 1000);
        set("max_neili",1000);
        set("force_factor", 40);
        set("atman", 100);
        set("max_atman", 100);
        set("mana", 300);
        set("max_mana", 300);
        
        

         
        set_skill("move", 200);
        set_skill("force", 150);
        set_skill("spells", 150);
        set_skill("unarmed", 140);
        set_skill("sword", 150);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
                
      set_skill("unarmed", 250);
        set_skill("throwing", 285);
        set_skill("force", 250);
        set_skill("parry", 267);
        set_skill("dodge", 269);
        set_skill("literate", 250);

        set_skill("nine-moon-steps", 268);
        set_skill("nine-moon-claw", 235+random(30));
        set_skill("nine-moon-force", 260);
        set_skill("nine-moon-sword", 270); 
        map_skill("dodge", "nine-moon-steps");
        map_skill("unarmed", "nine-moon-claw");
        map_skill("force", "nine-moon-force");
        map_skill("sword", "nine-moon-sword");
        
        set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
                (: perform_action, "dodge.lianhuanbu" :),
                (: perform_action, "unarmed.suicidal" :),
                
        }) ); 
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(1));
        carry_object(__DIR__"obj/n_stone")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 
