#include <ansi.h>
inherit NPC;

nosave object owner=0;

varargs void setskills(int i){}

protected object query_owner(){ return owner;}

void create()
{
	set_name("护法",({"hufa","hu fa",}));
	set("attitude", "friendly");
	set_level(40);
	setskills();
	setup();
}

int heal_up()
{
	object target;
	if( !environment() )
		return 0;
	if( !owner || !living(owner) || !environment(owner) )
	{
		call_out("leave", 1);
		return 1;
	}
	if( !is_fighting() )
	{
		if( owner->query("mana")<=10 )
		{
			call_out("leave", 1);
			return 1;
		}
		else if( !present(this_object(),environment(owner)) )
		{
			if( !inherits(ROOM,environment(owner)) )
			{
				call_out("leave", 1);
				return 1;
			}
			else if( !this_object()->move(environment(owner)) )
			{
				call_out("leave", 1);
				return 1;
			}
			else	tell_room(environment(owner),"\n"+name()+"走了过来。\n");			
		}
		else if( owner->is_fighting() )
		{
			target = SSERVER->offensive_target(owner);
			if( target && owner->is_killing(target->query("id")) )
			{
				message_vision(HIW"\n$N"HIW"护主心切，冲上前去，与$n"HIW"战成一团！\n\n"NOR,this_object(),target);
				kill_ob(target);
			}
		}
	}
	//有时间性的护法
	if( query("heal_up_time") )
	{
		this_object()->add("time",-1);
		if( query("time")<=0 )
		{
			call_out("leave", 1);
			return 1;
		}
	}
	if( owner->query("mana")>10 )
		owner->add("mana",-(1+random(3)));	
	return ::heal_up() + 1;
}

void leave()
{
	string str;
	if( owner )
		owner->set_temp("last_invocation",time());
	if( stringp(str=query("env/msg_mout")) )
		message_vision(str,this_object());
	else	message("vision",HIY + name() + "说道：今奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"+ name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),this_object() );
	destruct(this_object());
}

mixed invocation(object who)
{
	string str;
	int i;
	object *enemy;
	if( !who )
		return 0;
	owner = who;		
	set_level(who->query_level()*2/3);
	set("daoxing",who->query("daoxing")/3*2);
	i = QUEST_D->maxSkill(who);
	i = i-random(10);
	setskills(i);
	setup();
	powerup();
	if( !this_object()->move(environment(owner)) )
		return 0;
	if( stringp(str=query("env/msg_min")) )
		message_vision(str,this_object());
	else	message("vision",HIY "一道金光由天而降，金光中走出一个身穿金色战袍的将官。\n\n"+ name() + HIY"说道：末将奉法主召唤，特来护法！\n" NOR,environment(), this_object() );
	set_follow(who);
        set_temp("invoker",who);
        who->set_temp("invocation",this_object());	
        who->set("last_invocation",time());
			
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) 
	{
		if( enemy[i] && living(enemy[i]) ) 
		{
			kill_ob(enemy[i]);
			if( userp(enemy[i]) ) 
				enemy[i]->fight_ob(this_object());
			else
				enemy[i]->kill_ob(this_object());
		}
	}
	return 1;
}

void die()
{
	string str;
	if( stringp(str=query("env/msg_mout")) )
		message_vision(str,this_object());
	else	message("vision",HIY + name() + "说道：今奉法主召唤，现在已经完成护法任务，就此告辞！\n\n"+ name() + "化成一道金光，冲上天际消失不见了。\n" NOR, environment(),this_object() );
	destruct(this_object());
}

void unconcious()
{
	die();
}	