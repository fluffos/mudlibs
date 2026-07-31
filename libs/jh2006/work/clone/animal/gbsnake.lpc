// snake.c 丐帮弟子即将驯服的蛇
// Looklove 2000/10/23
//标记说明
//snake
//	owner	主人
//player
//	snake/succesee	记录驯蛇成功
//	snake/failure	记录驯蛇失败次数
//	snake/friendly	记录蛇的友善度
//	snake/aggress	记录蛇的凶残
//snake的最终攻击能力和aggress成正比，和friendly成反比

inherit NPC;

#include <ansi.h>

int do_clone(object me, object ob);

void create()
{
	set_name("蛇", ({ "snake","she" }) );
	set("race", "野兽");
	set("limbs", ({ "头部", "身体", "尾巴" }) );
	set("verbs", ({ "bite" }) );
	set("shen", -15000);
	set("attitude", "killer");
	set("age", 1+random(3));
	set("combat_exp", 9999999);
	set("no_get",1);
	set("max_qi",9999);
	set("eff_qi",9999);
	set("qi",9999);
	set("max_jing",9999);
	set("eff_jing",9999);
	set("jing",9999);
	set("max_jingli",9999);
	set("eff_jingli",9999);
	set("jingli",9999);
	set("neili",9999);
	set("jiali", 99);
	set("max_neili",9999);
	set("score", 10000);
	set_skill("force",300);
	set_skill("dodge",300);
	set_skill("parry",300);
	set_skill("unarmed",300);

	setup();
	
}

void kill_ob(object me)
{
	object snake = this_object();
	
	me->remove_killer(snake);
	remove_killer(me);
	message_vision(HIW"$n咻的钻进草丛不见了。\n"NOR,me,snake);
	destruct(snake);
}

void init()
{
	object me,snake;

	me = this_player();
	snake = this_object();

	if (me->query("snake/success") 
	    && !me->query("snake/failure") 
	    && !snake->query_temp("skillset") 
	    && snake->query("owner")==me->query("id"))
	{
		do_clone(snake, me);
       		if (random(me->query("snake/aggress"))>random(me->query("snake/friendly"))) {
			message_vision(BLU"$n突然凶性大发，照着$N的手就是一口。\n"NOR,me,snake);
       			message_vision(HIR"$N的鲜血顺着手腕流了下来！\n"NOR,me);
			me->apply_condition("snake_poison",4+me->query_condition("snake_poison"));
		}
		else message_vision(HIM"$n很友善地对着$N摇了摇尾巴。\n"NOR,me,snake);
		snake->set_leader(me);
       		message_vision("$N的蛇决定和$N一起行动。\n",me);
	}
	if (!living(snake)) {
		remove_call_out("dest");
		call_out("dest",1);
	}
} 

int do_clone(object snake, object me)
{
	int number,k_qi,k_neili,k_jing,k_jingli,jiali,friendly,aggress;
	
	snake->set("name",me->query("name")+"的蛇");
	snake->set_temp("owner",me->query("id"));
	
	number = (int)me->query("max_pot") /10;
	k_qi = (int)me->query("max_qi");
	k_jing = (int)me->query("max_jing");
	k_jingli = (int)me->query("eff_jingli");
	k_neili = (int)me->query("max_neili");
	jiali = (int)me->query_skill("force",1);
	friendly = (int)me->query("snake/friendly",1);
	aggress = (int)me->query("snake/aggress",1);
	
	
	snake->set_skill("force",number*10-100);
	snake->set_skill("dodge",number*10-100);
	snake->set_skill("parry",number*10-100);
	snake->set_skill("unarmed",number*10-100);
	
	snake->set("max_qi",k_qi);
	snake->set("eff_qi",k_qi);
	snake->set("qi",k_qi);
	snake->set("max_jing",k_jing);
	snake->set("eff_jing",k_jing);
	snake->set("eff_jingli",k_jingli);
	snake->set("max_jingli",k_jingli);
	snake->set("jingli",k_jingli);
	snake->set("jing",k_jing);
	snake->set("max_neili",k_neili);
	snake->set("neili",k_neili*2-1);
	snake->set("neili",k_neili);
	snake->set("jiali", jiali);
	snake->set("combat_exp",me->query("combat_exp"));

	snake->add_temp("apply/attack",  (int)(number*aggress/friendly));
	snake->set_temp("apply/dodge", (int)(number*aggress/friendly));
	
	snake->set_temp("skillset",1);
	return 1;
}

void dest()
{
	object owner,snake;
	string who;
	
	snake = this_object();
	
	if (!living(snake))
	{
		remove_call_out("dest");
		call_out("dest", 10);
		return;
	}

	who = snake->query_temp("owner");
	if (who) {
		owner=find_player(who);
		if (!owner) owner = find_living(who);

		if (owner) owner->delete_temp("snake");
	}

	message_vision(HIW"$N扭了扭尾巴，不知怎么就不见了。\n"NOR,snake);
	destruct(snake);
}

int hit_ob(object me, object victim, int damage)
{
	victim->apply_condition("snake_poison",victim->query_condition("snake_poison") + 6+random(5));
	return 1;
}

void relay_emote(object me,string arg)
{
	command(arg+" "+me->query("id"));
}
