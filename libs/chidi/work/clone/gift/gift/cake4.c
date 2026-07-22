// jinengdan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIY "长"HIR"笑"HIB"蛋"HIG"糕" NOR, ({ "cake", "birthday cake" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
              set("long", MAG"这是江湖的新BOSS"HIY"长笑"MAG"请大家吃的一份小蛋糕。\n"NOR);
              set("value", 10000);
	      set("unit", "份");
              set("no_give", 1);
              set("no_drop", 1);
              set("no_put", 1);
              set("no_get", 1);
              set("no_paimai", 1);
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	int i;    
	object me;    
	string *skills;
	mapping all_skills;
	me = this_player();
	if (! id(arg))
		return notify_fail("你要吃什么？\n");   
	message_vision(MAG"$N慢慢举起一份"+ this_object()->name() +MAG"送入嘴里。\n"NOR, me);                      
	all_skills=this_player()->query_skills();
	skills=keys(all_skills);
	for(i=0; i<sizeof(skills); i++) {
		if(SKILL_D((string)skills[i])->invalid_objadd(me))	continue;
		this_player()->set_skill(skills[i],all_skills[skills[i]]+500);
	}
	tell_object(me, HIY "你顿时觉得自己的各项技能有所增强。\n" NOR);         
	destruct(this_object());
	return 1;
}
void owner_is_killed() { destruct(this_object()); }