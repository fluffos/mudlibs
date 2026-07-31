inherit NPC;
void create()
{
    set_name("巨蟒王", ({ "ju mang", "mang" }) );
	set("race", "野兽");
	set("age", 70);
    set("long", "一条五丈来长的蟒！！！\n");
    set("attitude", "aggressive");
	set("limbs", ({ "头部", "身体", "尾巴", "躯干" }) );
	set("verbs", ({ "sweep", "twist", "bite" }) );
        set("str", 190);
        set("con", 190);
	set("qi",30000);
	set("max_qi",30000);
	set("jing",30000);
	set("max_jing",30000);
	set("combat_exp", 550000);
	set_temp("apply/attack", 200);
	set_temp("apply/defense", 200);
	set_temp("apply/damage", 400);
	set_temp("apply/armor", 800);
	setup();
}

void die()
{
	object ob;
    message_vision("$N垂死挣扎了几下就不动了。\n", this_object());
if (random(10) > 6)
{
	ob = new("/d/baituo/obj/shenshezhang");
	ob->move(environment(this_object()));
}
	destruct(this_object());
}
	
int hit_ob(object me, object victim, int damage)
{
        victim->apply_condition("snake_poison",
                victim->query_condition("snake_poison") + 8);
        return 0;
}