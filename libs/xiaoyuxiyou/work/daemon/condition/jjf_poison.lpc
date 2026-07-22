#include <ansi.h>

int update_condition(object me, int duration)
{
	me->receive_wound("sen", 10);
        me->receive_wound("kee", 10);
        me->set_temp("death_msg","瘟病发作死了。\n");
        me->apply_condition("jjf_poison", duration - 1);

        if( (int)me->query("kee") < (int)me->query("max_kee")/4 )
                message_vision("$N浑身颤个不停，似乎随时都会倒下去。\n", me);
        else if( (int)me->query("kee") < (int)me->query("max_kee")/2 )
                message_vision("$N面目浮肿，嘴中不断流出黄沫。\n", me);
        else	message_vision("$N脸色发黄，四肢颤个不停。\n", me);
        if( duration < 1 ) 
        {
        	if( me->query_temp("death_msg")=="瘟病发作死了。\n" )
        		me->delete_temp("death_msg");
        	return 0;
        }
        return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="阎罗地府" )
		return 0;
	if( random(who->query("max_force"))<500 )
		return 0;
	message_vision(HIB"$N"HIB"身上鬼气弥漫，五行瘟毒顿化灰灰。\n"NOR,who);
	return 1;
}