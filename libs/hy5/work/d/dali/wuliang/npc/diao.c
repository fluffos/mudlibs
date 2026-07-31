// fox.c
// Date: Sep.22 1997

inherit NPC;

void create()
{
        set_name("闪电貂", ({ "shandian diao", "shandiandiao" }) );
        set("race", "野兽");
        set("age", 4);
        set("long", "一只多疑成性的闪电貂。\n");
//        set("attitude", "aggressive");
        set("attitude", "peace");
        set("shen_type", -1);

        set("limbs", ({ "狐头", "狐身", "前爪", "后抓", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 100000);
 set("max_neili", 2000);
  set("max_qi", 2000);
   set("max_jing", 2000);
        set_temp("apply/attack", 200);
        set_temp("apply/defense", 200);
        set_temp("apply/armor", 3000);
        set_temp("apply/damage", 3000);

        setup();

        set("chat_chance", 10);
        set("chat_msg", ({
                "闪电貂向后挪了挪，很是戒备的神情。\n",
                "闪电貂瞪着多疑的眼光冲你看，全身一副很紧张的模样。\n",
        }) );
}

