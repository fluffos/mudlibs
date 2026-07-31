//Cracked by Roath
// animal: snake.c
// Marz@xkx 11/12/96

inherit NPC;

void create()
{
        set_name("蝮蛇", ({ "snake", "she" }) );
	set("race", "野兽");
	set("limbs", ({ "头部", "身体", "前脚", "后脚", "尾巴" }) );
	set("verbs", ({ "bite" }) );
        set("long", "这是一只南方丛林里出没的蛇，习性与一般的蛇大为不同。\n");
        set("attitude", "aggressive");

        set("str", 40);
        set("con", 30);
        set("int", 40);
        set("dex", 10);


        set("combat_exp", 1000);

        set_temp("apply/attack", 25);
        set_temp("apply/damage", 10);
        set_temp("apply/armor", 2);

        setup();
}



mixed hit_ob(object me, object victim, int damage_bonus, int factor)
{
	victim->apply_condition("snake_poison", 10 +
		victim->query_condition("snake_poison"));
}

