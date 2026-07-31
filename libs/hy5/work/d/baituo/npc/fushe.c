inherit NPC;
void create()
{
    set_name("蝮蛇", ({ "fu she", "snake", "she" }) );
	set("race", "野兽");
	set("age", 10);
    set("long", "一条二尺来长的腹蛇。\n");
    set("attitude", "peaceful");
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "twist", "bite" }) );
	set("combat_exp", 3000);
	set_temp("apply/attack", 20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage", 20);
	set_temp("apply/armor", 20);
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
                victim->query_condition("snake_poison") + 8);
        return 0;
}