// close.h 
#include <ansi.h>
int do_close(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");

    if( !arg || arg == "" || arg != "lid")
                return notify_fail("你要关什么？\n");

        if( !me->query("marks/open") )      // 判断此时丹炉的盖子是打开还是关上的
                return notify_fail("丹炉的盖子没有打开。\n");

    if( arg == "lid" )
        {
        message_vision("$N轻手轻脚的将丹炉的盖子盖上。\n", ob);
        me->delete("marks/open");           // 如果有人把丹炉的盖子关上，那么去掉此标记。
        return 1;
        }

}