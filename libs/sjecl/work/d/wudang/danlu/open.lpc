// open.h
#include <ansi.h>
int do_open(string arg)
{
        object me, ob;
        me = this_object();
        ob = this_player();
        
        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");

    if( !arg || arg == "" || arg != "lid")
                return notify_fail("你要打开什么？\n");

        if( me->query("marks/open") )           // 判断丹炉盖子打开还是关上的。
                return notify_fail("丹炉的盖子已经是打开的了。\n");

        if( me->query("marks/doing") 
         || me->query("marks/aoyao")
         || me->query("marks/fired"))           // 如果有人正在炼丹，不能开盖子。
              {
                message_vision(RED"\n$N突然手尖一阵巨痛，手指被火燎了一下。\n"NOR,ob);
                return 1;
              }

    if( arg == "lid" )
        {
                message_vision("$N把丹炉的盖子打开。\n", ob);
                me->set("marks/open", 1);       // 如果打开盖子加此标记。
                return 1;
        }

}
