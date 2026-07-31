// wolfdog.c

inherit NPC;

void create()
{
        set_name("恶犬", ({ "e quan", "dog" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只吐着长舌头的恶犬。\n");
        set("attitude", "aggressive");
        
        set("str", 26);
        set("cor", 30);

        set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 1000);
        set("chat_msg_combat", ({
                (: this_object(), "random_move" :),
                "恶犬大声吠叫：汪！汪！汪！汪！汪！汪！\n",
                "恶犬突然跳了起来，口中乱咬，却不知道是在咬谁。\n"
        }) );
                
        set_temp("apply/attack", 15);
        set_temp("apply/damage", 6);
        set_temp("apply/armor", 2);

        setup();
}

