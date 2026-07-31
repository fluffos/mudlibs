// Jay 5/23/96
inherit NPC;
void create()
{
        set_name("秃鹰", ({ "tu ying", "ying", "tu" }) );
        set("race", "野兽");
        set("age", 3);
        set("dex", 1000);
        set("long", "一只既丑陋，又威武的秃鹰。\n");
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 130000);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);
        set("chat_chance", 10);
        set("chat_msg", ({
        "秃鹰「嘎嘎嘎」地叫了几声。\n",       
                  "秃鹰在沙地上跳跃着。\n",
        }) );
        setup();
}
