#include <ansi.h>
int valid_leave(object me,string dir)
{
    object room;
    int i;
    string msg,*color=({HIR,HIW,HIG,HIB,HIY,HIM,HIC});
    if (dir!=me->query_temp("hz_huayuan/last_dir"))
    {
        me->add_temp("hz_huayuan/getout",1);
        me->add_busy(random(4));
    }
    if (me->query_temp("hz_huayuan/getout")>25)
    {
        if (room=load_object(__DIR__"td_huayuan9"))
        {
            msg="\n";
            for (i=0;i<18-random(4);i++)
            {
                msg+=color[random(sizeof(color))]+"囧  ";
            }
            me->delete_temp("hz_huayuan");
            me->move(room);
            return notify_fail(msg+"\n");
        }
    }
    me->set_temp("hz_huayuan/last_dir",dir);
    return ::valid_leave(me, dir);
}

