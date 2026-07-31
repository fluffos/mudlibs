// pour.h
#include <ansi.h>

int do_pour(string arg)
{
        string hehe, what;
object me, ob, obj;
        me = this_object();
        ob = this_player();
        if( !arg
        ||  sscanf(arg, "%s in %s", hehe, what) != 2
               )
                return notify_fail("你要干什么？\n");

        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中！\n");

        if( !me->query("marks/open", 1) )
                return notify_fail("丹炉的盖子没有打开。\n");

        if( !objectp( obj = present(hehe, ob)))   // 如果你身上的物品的ID不对，不能往丹炉里加水。
                return notify_fail("你身上没有"+hehe+"，如何往丹炉里加水？\n");
                
        if( !obj->query("liquid/type"))           // 如果你身上的物品不是盛水的器皿，不能往丹炉里加水。
                return notify_fail(obj->name()+"不是盛水的器皿！\n");

        if( !obj->query("liquid/remaining") )     // 判断你身上盛水的器皿中是否还有水。
                return notify_fail(obj->name() + "里面已经一滴不剩了。\n");

        message_vision("$N将一些"+ obj->query("liquid/name") +"从"+ obj->name() +"倒进丹炉。\n", ob);
        obj->add("liquid/remaining", -1);
        me->add("liquid/remaining", 1);
        me->set("liquid/name", obj->query("liquid/name"));
        return 1;
}
