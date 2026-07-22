// killer.c
//#include <ansi.h>
int update_condition(object me, int duration)
{
    if (duration < 1) {
        return 0;
    }
    me->apply_condition("get_key", duration - 1);
    return 1;
}
