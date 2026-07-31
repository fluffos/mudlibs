 inherit NPC;
void create()
{
    set_name("宾奴", ({ "catty" }) );
        set("race", "野兽");
        set("age", 3);
        set("gender", "雌性");
        set("long", "阴宾所养的波斯猫\n");
        set("combat_exp", 10000);
        set("attitude","peaceful");
        set("chat_chance",3);
        set("chat_msg",({
                "白猫咪呜叫了一声。\n",
                "白猫蜷在你脚边打盹。\n",
        }) );
        set("limbs", ({ "头部", "身体","尾巴" }) );
        set("verbs", ({ "bite","claw" }) );
        set_temp("apply/dodge", 200);
        setup();
}   
