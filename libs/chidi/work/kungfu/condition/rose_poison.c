// rose_poison.c
#include <ansi.h>
int update_condition(object me, int duration)
{
    me->receive_wound("jing", 20);
    me->receive_damage("qi", 10);
    me->apply_condition("rose_poison", duration - 1);
    tell_object(me, HIG "ÄãÖÐµÄ" HIR "»ðÃµ¹å¶¾" HIG "·¢×÷ÁË£¡\n" NOR );
    me->set_temp("die_for","ÖÐ»ðÃµ¹å¶¾¶¾");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return 1;
}
