// Jay 5/23/96
inherit NPC;
void create()
{
        set_name("隼", ({ "sun", "ying" }) );
        set("race", "野兽");
        set("age", 3);
        set("dex", 1000);
        set("long", "一只威武小鹰。\n");
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 13000);
        set_temp("apply/attack", 3);
        set_temp("apply/defense", 5);
        set_temp("apply/armor", 1);
        set("chat_chance", 10);
        set("chat_msg", ({
        "隼「欧！！！」地长啸了几声。\n",       
                  "隼在林中飞上飞下。\n",
        (: random_move :)
        }) );
        setup();
}
