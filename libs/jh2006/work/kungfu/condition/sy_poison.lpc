// rose_poison.c

#include <ansi.h>

int update_condition(object me, int duration)
{
    me->receive_wound("jing", 20*(1+random(10)));
 	me->apply_condition("sy_poison", duration - 1);
	tell_object(me, HIG "一股热气涌入心头，你不禁烦恶欲呕。你中的" HIR "大手印掌毒" HIG "发作了！\n" NOR );
        message("vision", me->name() + "面色潮红，步履蹒跚，四肢乱颤站立不稳。\n",
            environment(me), me);
        if( duration < 1 ) return 0;
	return 1;
}
