inherit NPC;
void create()
{
    set_name("眼镜蛇", ({ "yanjing she", "yanjing", "snake", "she" }) );
	set("race", "野兽");
	set("age", 10);
    set("long", "一条眼镜蛇，对着你立了起来。\n");
    set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "twist", "bite" }) );
	set("combat_exp", 4500);
	set_temp("apply/attack", 25);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 10);
	set_temp("apply/armor", 10);

	setup();
}

void init()
{
        object ob = this_player();
        ::init();
        if (interactive(ob) &&
                !ob->query_skill("hamagong", 1)) {
                        this_object()->kill_ob(this_player());
        }
}

int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 10);
        return 0;
}