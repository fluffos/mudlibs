inherit NPC;
void create()
{
    set_name("眼镜王蛇", ({ "yanjing wangshe", "snake", "she", "wangshe" }) );
	set("race", "野兽");
	set("age", 10);
    set("long", "一条三尺来长的眼镜王蛇。\n");
    set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "twist", "bite" }) );
	set("combat_exp", 5500);
	set_temp("apply/attack", 55);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	setup();
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 15);
        return 0;
}