// heaven_soldier.c

#include <ansi.h>

inherit NPC;
void backattack();
void create()
{

	set_name("神龙奇蛇", ({ "jin she", "she" }) );
	set("race", "野兽");
	set("age", 2);
	set("long", "一只让人看了起毛骨悚然的神龙奇蛇	。\n");
	set("attitude", "peaceful");
	set("str", 30);
	set("cor", 30);
	set("limbs", ({ "头部", "身体", "七寸", "尾巴" }) );
	set("verbs", ({ "bite" }) );
        set("vendetta/authority",1);

	set("str", 60);
	set("dex", 30);
	set("con", 30);
	set("qi", 500 + random(300));
	set("max_qi", 500 + random(300));
	set("jing", 500 + random(300));
	set("max_jing", 500 + random(300));

	set("combat_exp", 50000);
	set_temp("apply/attack", 50);
	set_temp("apply/damage", 50);
	set_temp("apply/armor", 50);
	set_temp("apply/defence",100);

	setup();

}

int heal_up()
{
	if( environment() && !is_fighting() ) {
		call_out("leave", 1);
		return 1;
	}
	return ::heal_up() + 1;
}

void leave()
{
	object owner;
	message("vision",
		 name() + "吱吱的发出了几声怪声！\n\n"
		+ name() + "钻进附近的草地就消失不见了。\n" , environment(),
		this_object() );
        if(objectp(owner=this_object()->query("possessed")))
		owner->add_temp("max_guard",-1);
	destruct(this_object());
}

void invocation(object who, int level)
{
	int i;
	object *enemy;
	set_skill("parry", 170 + random(level));
	set_skill("dodge", 170 + random(level));
	set_skill("unarmed", 170 + random(level));
	set("combat_exp", 100000 + random(level/2*level*level));
	message("vision",
		 name() + "吱吱的怪叫了几声,吐了吐舌头！\n" NOR,
		environment(), this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) enemy[i]->fight_ob(this_object());
			else enemy[i]->kill_ob(this_object());
		}
	}
	set_leader(who);
	set("possessed",who);
}
void backattack()
{
	int i;
	object owner, *enemy;
	if(objectp(owner=this_object()->query("possessed")))
	{
		enemy = this_object()->query_enemy();
        i = sizeof(enemy);
        while(i--) {
                if( enemy[i] && living(enemy[i]) ) {
                        owner->kill_ob(enemy[i]);
                        enemy[i]->kill_ob(owner);
                }
        }

	}

}

void die()
{
	object owner;
        if(objectp(owner=this_object()->query("possessed")))
                owner->add_temp("max_guard",-1);
	backattack();
	::die();
}

int hit_ob(object me, object ob, int damage)
{
        ob->apply_condition("snake_poison", 50);
        ob->apply_condition("ill_fashao",50);
        ob->apply_condition("ill_kesou",50);
        ob->apply_condition("ill_shanghan",50);
        ob->apply_condition("ill_zhongshu",50);
        ob->apply_condition("ill_dongshang",50);
        tell_object(ob, HIG "你觉得被咬中的地方一阵麻痒！\n" NOR );
}