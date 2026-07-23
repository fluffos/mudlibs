 inherit NPC;
#include <ansi.h>

void create()
{
        set_name("谢长卿", ({ "xie changqing" }) );
        set("gender", "男性");
        set("age", 25);
        set("long",
"一个年轻而英俊的少年，他甚至在颤抖着，英俊的面庞上，也蒙着
一层死灰之色。。\n"
);
      
        set("chat_chance", 1);
        set("chat_msg", ({
"谢长卿喃喃道：“我还年轻，我不能就这样无声无息地死去，而且那时
谷中再无他人，即使我作了昧心之事，又有谁会传将出去，唉！我想
人人都该为自己打算吧。”\n",
        }) ); 
        set("fly_target",1); 
        set("attitude", "friendly");
        set("title",HIG"点苍"NOR);
        set("nickname", HIG"落英剑"NOR);
        set("score", 0);
        set("reward_npc", 1);
        set("difficulty",2);
        set("class","legend");
        
        set("combat_exp", 3500000);        
        set("int", 30);
        set("cps", 20);
        set("spi", 30);
        set("fle",60);
        set("per",40);
        set("str",40);
        
        set("neili", 1000);
        set("max_neili",1000);
        set("force_factor", 90);
        set("atman", 1000);
        set("max_atman", 1000);
        set("mana", 500);
        set("max_mana", 500);
        
        set("resistance/kee",40);
        set("resistance/gin",40);
        set("resistance/sen",40);
        

          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 150);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
        set_skill("fall-steps",150);
        set_skill("meihua-shou",150);

        
        map_skill("unarmed","meihua-shou");
        map_skill("force", "qidaoforce");
        map_skill("dodge","fall-steps");


        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup(); 
        add_money("gold", random(5));
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/clone/misc/cloth")->wear();
} 
 

