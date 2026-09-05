// npc: hainiao.c   海鸟
// hongdou 98.10.12

inherit NPC;

void create()
{
        set_name("海鸟", ({ "hai niao", "niao" }) );
        set("race", "野兽");
        set("age", 3);
        set("long", "一只雪白的海鸟，海边经常能够见到。\n");
        set("attitude", "peaceful");

        set("limbs", ({ "头部", "身体", "翅膀", "爪子", "尾部" }) );
        set("verbs", ({ "bite", "claw" }) );

        set("combat_exp", 800);
        set_temp("apply/attack", 4);
        set_temp("apply/defense", 6);
        set_temp("apply/armor", 2);

        set("chat_chance", 10);
        set("chat_msg", ({
		"海鸟「吱吱」地叫了几声。\n",
		"海鸟在海面上盘旋飞翔。\n",
        }) );

        set("shen_type",1);set("score",200);setup();
}
