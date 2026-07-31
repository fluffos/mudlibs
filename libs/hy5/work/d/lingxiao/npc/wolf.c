//LUCAS 2000-6-18
inherit NPC;

void create()
{
        set_name("雪狼", ({ "xue lang","wolf", "lang" }) );
        set("race", "野兽");
        set("age", 5);
        set("long", "一头雪白的雪狼，昂首直立，两眼放着绿光，是大雪山上凶猛的野兽。\n");
        set("attitude", "aggressive");

        set("str", 26);
        set("cor", 30);
        set("limbs", ({ "头部", "身体", "腿部", "尾巴",}) );
        set("verbs", ({ "bite" }) );

        set("combat_exp", 5000);

        set("chat_chance",50);
        set_temp("apply/attack", 25);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 18);
        set_temp("apply/defence",20);

        setup();
}

