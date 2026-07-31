inherit NPC;
void create()
{
        set_name("牦牛", ({ "mao niu","niu" }) );
        set("race", "野兽");
        set("age", 20);
        set("long", "一只披着尺许长毛的牦牛，正在低头吃草。\n");

        set("limbs", ({ "头部", "身体", "尾巴" }) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 100000);

        setup();
}


