// scorpion_poison.c



int update_condition(object me, int duration)
{
    me->receive_wound("jing", 10);
//    me->receive_wound("kee", 10);
//    me->receive_damage("sen", 10);
    me->receive_damage("qi", 10);
    me->apply_condition("scorpion_poison", duration - 1);
    tell_object(me, HIG "你感到呼吸困难，四肢渐渐肿了起来。"NOR"\n" );
	if( duration < 1 ) return 0;
	return 1;
}
