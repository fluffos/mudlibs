// NPC : /d/wudang/npc/xiong.c 熊

inherit NPC;
void create()
{
        set_name("大白熊", ({ "bai xiong", "xiong", "baixiong" }) );
        set("race", "野兽");
        set("age", 6);
        set("con", 100);
        set("str", 100);
        set("long", "一只毛长身巨，状如大牯牛的大白熊。\n");
        set("attitude", "aggressive");
        set("limbs", ({ "头部", "身体", "前爪", "后爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("combat_exp", 250000);
	set_temp("apply/attack", 60);
	set_temp("apply/defense", 80);
        set_temp("apply/damage", 60);
        set_temp("apply/armor", 70);
        setup();
}
void die()
{
       message_vision("\n$N惨嚎一声，慢慢倒下死了！\n", this_object());
       new(FOOD_D("xzhang"))->move(environment(this_object()));
       new(ARMOR_D("xiongpi"))->move(environment(this_object()));
       destruct(this_object());
}
