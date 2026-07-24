void greeting(object me)
{
    string str = log_time();

    if (!objectp(me) || environment(me) != environment())
        return;

    if (!userp(me))
        return;
 
    if (str[0..2] == "Jan" &&
        atoi(str[4..5]) > 0 && atoi(str[4..5]) < 5)
    {
        if ( // me->query("combat_exp") > 500000 &&
            me->query("mudring/happy02") < 1)
        {
            if (me->query("combat_exp") < 200000)
            {
                me->add("potential", 20000);
                me->add("combat_exp", 20000);
                me->add("daoxing", 20000);
            }
            me->add("potential", 50000);
            me->add("combat_exp", 50000);
            me->add("daoxing", 50000);

            me->add("mudring/happy02", 1);
            MONITOR_D->mudring_log("RINGDAY", me, " got new year gift...");
            MONITOR_D->report_debug_object_msg(me, " got new year gift...");
        }
        tell_object(me, BLINK HIM"\n\n\n\n\t\tHappy New Year!\n\n"NOR);
        tell_object(me, BLINK HIM"\n\n\t\t三界神话巫师组祝您新年快乐！\n\n"NOR);
    }
}

