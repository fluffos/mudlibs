 inherit NPC;
void create()
{
        set_name("牦牛", ({ "bull" }) );
        set("race", "野兽");
        set("age", 10);
        set("long", "一只长着长长黑毛的西藏牦牛。\n"); 
        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );
        set("combat_exp", 300000);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
   
        setup();
} 
