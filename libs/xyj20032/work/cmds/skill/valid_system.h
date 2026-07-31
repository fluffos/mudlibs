// system busy.
int valid_system(object me)
{
    if (!wizardp(me) && userp(me))
    {
        if (uptime() - me->query_temp("system_busy") < 5)
            return notify_fail("系统忙，请稍后。\n");
    }
    me->set_temp("system_busy", uptime());
    return 1;
}
