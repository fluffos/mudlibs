// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
        me->receive_wound("sen", 20);
        me->apply_condition("mihun_poison", duration - 1);
        tell_object(me, HIR "你觉得四肢麻木，身体中的元神正一点点的流失．\n" NOR);
        if( duration < 1 ) return 0;
        return 1;
}

int no_apply(object who)
{
	string fam;
	if( !who || !living(who) )
		return 0;
	fam = who->query("family/family_name");
	if( !fam || fam!="南海普陀山" )
		return 0;
	if( random(who->query("max_force"))<300 )
		return 0;
	message_vision(HIY"$N"HIY"身上佛光一闪，结果诸多幻象顿如井中水月。\n"NOR,who);
	return 1;
}