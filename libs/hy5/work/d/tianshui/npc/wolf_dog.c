// wolf_dog.c

inherit NPC;

void create()
{
        set_name("大狼狗", ({ "wolf dog","dog" }) );
        set("race", "野兽");
        set("age", 3);
	set("long", "这是一只肥大的狼狗，浑身毛色油黑，眼睛里散发着凶猛的光。\n");
        set("attitude", "aggressive");

        set("max_kee", 500);
        set("max_gin", 500);
        set("max_sen", 500);
        
        set("combat_exp", 50000);
        set("limbs", ({ "头部", "身体", "尾巴","前脚", "後脚"}) );
        set("verbs", ({ "bite","claw" }) );
        set("str",20);
        set("cor",30);
        set("chat_chance", 20);
        set("chat_msg_combat", ({
                "大狼狗一声嚎叫向你扑来!\n",
         }));

	set_temp("apply/attack", 35);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 20);
        setup();
}
