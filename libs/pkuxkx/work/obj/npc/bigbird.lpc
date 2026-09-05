#pragma save_binary
// heaven_soldier.c

#include <ansi.h>

inherit NPC;

void create()
{
	
	set_name(HIM"七彩孔雀"NOR, ({ "kongque bird", "bird" }) );
	set("long", "这是一只伴随燃灯古佛的灵鸟。\n");
	set("attitude", "friendly");
	set("race", "野兽");
	set("max_gin", 2000);
	set("max_kee", 2000);
	set("max_sen", 2000);

	set("max_atman", 500);
	set("eff_atman", 500);
	set("atman", 500);
	set("max_mana", 500);
	set("mana", 500);
	set("eff_mana", 500);
	set("max_force",1000);
	set("eff_force",1000);
        set("force",1000);
	set("str", 90);
	set("cor", 90);
	set("cps", 95);
	set("limbs", ({ "头部", "身体","翅膀","尾巴","爪子" }) );
	set("verbs", ({ "bite","claw" }) );
	set("combat_exp", 500000);
	set("chat_chance", 15);
	set("chat_msg_combat", ({
		name() + "吱吱鸣叫着，叫声中透着杀机。\n"
	}) );

	set_temp("apply/attack", random(100));
	set_temp("apply/damage",random(100));
	set_temp("apply/armor", random(300));
        set_temp("apply/dodge", 100+random(250));

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
		HIY "一道彩霞由天而降，化为一只美丽的孔雀，加入了战团！\n" NOR,
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
