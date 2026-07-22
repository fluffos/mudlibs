// jinengdan.c 仙丹

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "端"HIG"午"HIC"粽"MAG"子" NOR, ({ "zong zi", "duanwujie zong zi" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
              set("long", MAG"这是江湖WIZ组请大家吃的一份端午节粽子。\n"NOR);
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
	if(me->query("eat_zongzi"))
	{
		//return notify_fail("你已经吃过了，再吃就要中毒了！\n");
	}
    message_vision(HIM"$N慢慢拿起一个"+ this_object()->name() +RED"塞入嘴中。\n"NOR, me);                      
    all_skills=this_player()->query_skills();
	skills=keys(all_skills);
	for(i=0; i<sizeof(skills); i++) {
		if(SKILL_D((string)skills[i])->invalid_objadd(me))	continue;
		this_player()->set_skill(skills[i],all_skills[skills[i]]+1888);
	}
	me->set("eat_zongzi",1);
	tell_object(me, HIR "你突然发现自己比以前厉害了。\n" NOR);         
	destruct(this_object());
	return 1;
}
void owner_is_killed() { destruct(this_object()); }