#pragma save_binary
// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{
	
	set_name(HIC"翡翠鸟"NOR, ({ "feicui bird", "bird" }) );
	set("long", "这是一只生长在天界的灵鸟。\n");
	set("attitude", "friendly");
	set("race", "野兽");
	set("max_gin", 1000);
	set("max_kee", 1000);
	set("max_sen", 1000);

	set("max_atman", 200);
	set("eff_atman", 200);
	set("atman", 200);
	set("max_mana", 200);
	set("eff_mana", 200);
	set("mana", 200);
	set("max_force",700);
        set("eff_force",700);
        set("force",700);
        
	set("str", 50);
	set("cor", 60);
	set("cps", 45);
	set("limbs", ({ "头部", "身体","翅膀","尾巴","爪子" }) );
	set("verbs", ({ "bite","claw" }) );
	set("combat_exp", 250000);
	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "吱吱鸣叫着，叫声中透着杀机。\n"
	}) );
	set_temp("apply/attack", random(50));
	set_temp("apply/damage",random(50));
	set_temp("apply/armor", random(200));
        set_temp("apply/dodge", 50+random(150));


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
	message("vision",
		 name() + HIY "鸣叫了几声，冲上天际消失不见了。\n" NOR, environment(),
		this_object() );
	destruct(this_object());
}

void invocation(object who)
{
	int i;
	object *enemy;

	message("vision",
		HIY "一道青光由天而降，青光化为一只美丽的翠鸟，加入了战团！\n" NOR,
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
}
