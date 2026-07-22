// Filename : /cmds/std/unride.c
// by mop 99.8
#include <ansi.h>
inherit F_CLEAN_UP;
void create() { seteuid(getuid()); }
int main(object me, string arg)
{
        object obj;

        if(!me->query_temp("riding") || !arg
           || !objectp(obj=present(arg,me)) || !obj->query("equipped") )
        return notify_fail("你并没有骑这匹座骑呀！\n");

        if( obj->unequip() )
        {
         if( random(me->query_dex()) > 10 )
         message_vision(HIC"$N矫捷地一按马鞍，飞身从"NOR
               +obj->query("name")+HIC"上一跃而下！真帅啊\n"NOR,me);
         else
         message_vision(CYN"“扑通”一声，$N从"NOR
               +obj->query("name")+HIB"上滚了下来，满脸是泥！\n"NOR,me);
         obj->move(environment(me));

         if( obj->query("start_room") )
         {
          message_vision("$N"HIM"一声嘶鸣，撒开四蹄扬尘而去！\n"NOR,obj);
          obj->move(obj->query("start_room"));    
         }
        }
        return 1;
}      

int help(object me)
{
        write(@HELP
指令格式 : unride | xia
 
这个指令可以让你从骑着的已驯养的动物上跳下来。
 
HELP
    );
    return 1;
}
 

