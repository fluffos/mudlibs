//城门
// By Zine 23 Nov 2010

inherit ROOM;
#include <ansi.h>

int valid_leave(object me,string dir)
{
    if (me->query_temp("ming_adv_tasks/task")&&me->query_temp("ming_adv_tasks/task")!="myself")
    {
        return notify_fail("等这件政务出了结果再离开吧。\n");
    }
    if (time()-(int)me->query_temp("ming/start_query_officer")<60)
    {
        return notify_fail("你已经找了书吏调阅本部官员档案，他马上就会回来，再等等吧。\n");
    }
    return ::valid_leave(me,dir);
}