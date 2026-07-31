// wugong.c

#include <ansi.h>

inherit NPC;

void ran_action();

void create()
{
	set_name(HIR"红蜈蚣"NOR, ({ "hong wugong","wugong" }) );
	set("race", "野兽");
	set("age",2);
	set("max_kee",900);

	set("long", "这是一条通身火红的大蜈蚣。\n");

	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );
/*
	set("chat_chance",5);
	set("chat_msg",({
	(: ran_action :),
 }));
*/
	set("combat_exp", 10000);
	set_temp("apply/attack",60);
	set_temp("apply/defense",25);
	setup();
}
/*
void ran_action()
{
	object env,zhi;

	if(!env = environment())
		return;

	zhi = present("zi lingzhi",env);

	tell_room(env,objectp(zhi)?sprintf("%s绕着%s转了一圈，还不时的蹭蹭%s。\n",
		name(),zhi->name(),zhi->name()):sprintf("%s满地乱爬，好像在找什么东西。\n",
		name()));
}
*/
int hit_ob(object who,int wound)
{
	int n;

	if(!who || !userp(who))
		return 0;

	if(!objectp(present("bidu zhu",who)))
	{
		n = who->query_condition("wugong_poison");
		who->apply_condition("wugong_poison", random(10)+5+n);
		tell_object(who,HIR"\n你只觉得被红蜈蚣伤到的地方一阵麻痒，大概是中毒了！！\n\n"NOR);
		return 1;
	}
	return 0;
}

void die()
{
	object who = query_temp("last_damage_from");

	if(objectp(who)
	&& who->query("quest/shaolin_quest/name") == "紫灵芝" )
		who->set("quest/shaolin_quest/killed_wugong",1);
	::die();
}

int heal_up()
{
	if(!is_fighting() && living(this_object()))
	{
		call_out("go_away",2);
		return 1;
	}
	return ::heal_up() + 1;
}

void go_away()
{
	if(!living(this_object()) || is_fighting())
		return;

	if(environment())
		tell_object(environment(),name()+"一扭身子钻到石头缝里不见了。\n");
	destruct(this_object());
}
