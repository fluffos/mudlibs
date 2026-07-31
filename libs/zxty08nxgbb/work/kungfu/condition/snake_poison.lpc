// snake_poison.c

int update_condition(object me, int duration)
{
    if(me->query_temp("nopoison")) return 0;
    me->receive_wound("qi", 20);
    me->receive_damage("jing", 10);
    me->apply_condition("snake_poison", duration - 1);
    if (! duration%5){
        tell_object(me, HIG "你中的蛇毒发作了！\n" NOR );
    }
    me->set_temp("die_for","中蛇毒毒");
    me->delete_temp("last_damage_from");
    if( duration < 1 ) return 0;
    return 1;
}
