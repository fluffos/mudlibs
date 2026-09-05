#include <ansi.h>

int do_sao()
{
    object me=this_player();
    int loc=this_object()->query("loc");
    if (!present("da saoba",me))
    {
        tell_object(me,"你身上没有扫把，怎么扫地？\n");
        return 1;
    }
    if (me->is_busy())
    {
        tell_object(me,"你正忙着呢。\n");
        return 1;
    }
    if (me->query_temp("qznewbiejob/task1/"+loc+"/finish"))
    {
        if (random(1000)>950)
        {
            me->set_temp("qznewbiejob/task1/"+loc+"/finish",0);
            tell_object(me,"你胡乱拨扫，把落叶又弄得到处都是。\n");
            return 1;
        }
        tell_object(me,"这里已经被打扫的一尘不染了。\n");
        return 1;
    }
    if (me->query_temp("qznewbiejob/task1/sao_degree")>5+random(5))
    {
        tell_object(me,"这里已经被打扫的一尘不染了。\n");
        me->delete_temp("qznewbiejob/task1/sao_degree");
        me->set_temp("qznewbiejob/task1/"+loc+"/finish",1);
        return 1;
    }
    message_vision("$N挥舞着大扫把，开始清扫这里的落叶。\n",me);
    me->add_busy(3+random(3));
    if (me->query_temp("qznewbiejob/task1/start"))
    {
        me->add_temp("qznewbiejob/task1/sao_degree",1);
    }
    return 1;
}

int valid_leave(object me,string dir)
{
    int loc=this_object()->query("loc");
    if (me->query_temp("qznewbiejob/task1/"+loc+"/finish")
        &&!me->query_temp("qznewbiejob/task1/rework")
        &&random(30)>25)
    {
        me->delete_temp("qznewbiejob/task1/"+loc+"/finish");
        me->set_temp("qznewbiejob/task1/rework",1);
        tell_object(me,"你见打扫完这一片，正欲离去，忽然刮起了大风，把落叶又吹得满地都是了。\n");
    }
    return 1;
}