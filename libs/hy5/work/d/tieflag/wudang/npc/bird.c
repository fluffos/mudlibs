 // dog.c
inherit NPC; 
void create()
{
        set_name("麻雀", ({ "bird" }) );
        set("race", "野兽");
        set("age", 1);
        set("long", "咭咭喳喳的一只小麻雀。\n");
        
        set("limbs", ({ "头部", "身体", "翅膀", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) ); 
        set("chat_chance", 50);
        set("chat_msg", ({
                (: this_object(), "random_move" :),
                "咭咭。\n",
                "喳喳。\n",
        }));
        set("arrive_msg","飞了过来");
        set("leave_msg","飞开了");
        set_temp("apply/dodge", 100);
        set_temp("apply/attack", 10);
        set_temp("apply/armor", 3); 
        setup();
}      
