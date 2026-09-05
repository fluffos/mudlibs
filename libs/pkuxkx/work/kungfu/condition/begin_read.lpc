#include <login.h>
int update_condition(object me, int duration)
{
object room;
room=load_object("/d/yuewangmu/yuewangmu");
 if (duration < 1)
{
if(environment(me)==room)
{write("你长期在墓中，由于缺氧，你头昏眼花实在呆不住了，就跑出了墓室！\n");
me->move("/d/yuewangmu/muhou");
return 0;
}
return 0;
}
        me->apply_condition("begin_read", duration - 1);
        return 1;
}
