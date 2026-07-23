	 inherit NPC;
#include <ansi.h>
void create()
{
        set_name("傅红雪", ({ "hongxue", "fu hongxue", "fu hong xue" }) );
        set("gender", "男性" );
        set("age", 24);
        set("cps", 30);
        set("int", 30);
        
        set("attitude","friendly");
        set("cor",100);
        
        set("class", "bandit");
        
        set("reward_npc", 1);
        set("difficulty", 30);
        set("max_qi",100000);
        set("max_jing",100000);
        set("max_sen",100000);
        set("max_neili", 15000);
        set("neili", 15000);
        set("courage",1000);
        set("force_factor", 300);
        set("no_busy", 5);

        
        set("long","傅红雪的手里握着刀，一柄形状很奇特的刀，刀鞘漆黑，刀柄漆黑。
无论他在作什么的时候都没有放过这柄刀。\n"); 
        set("combat_exp",10000000);
        set("score", 1000);
        set("no_busy",5);
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
            
            (: perform_action, "blade.kuaidao" :)
            }) );

        set("chat_chance", 1);
        set("chat_msg", ({
                "傅红雪正在吃饭，吃一口饭，配一口菜，吃得很慢。\n",
                "傅红雪漆黑的刀，漆黑的衣服，漆黑的眸子，黑得发亮！\n",
        }) );
        

        set_skill("parry", 200);

        set_skill("dodge", 200);
        set_skill("blade", 300);
        set_skill("fengyu-piaoxiang",200);
        set_skill("meihua-shou",200);
        set_skill("unarmed",200);
        
        map_skill("unarmed","meihua-shou");
        map_skill("dodge","fengyu-piaoxiang");
        map_skill("parry","shortsong-blade");

        map_skill("move","fengyu-piaoxiang");
        
        setup();
        carry_object("/clone/misc/cloth")->wear();
        if (!random(10)) carry_object(__DIR__"obj/fbblade")->wield();
                else carry_object(__DIR__"obj/bblade")->wield();
}      

void die()
{
        object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
                me = owner;
        } 
        me->set_temp("wanma/傅红雪_ma",1);
        ::die();
}  