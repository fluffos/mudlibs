// fill.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj;
    
    if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");

    if(!arg)
    	     return notify_fail("你要在什么东西里装水？\n");
    	     
    if(!objectp(obj = present(arg, me)) )
    	     return notify_fail("你身上没有这样东西。\n");
    
    if(!obj->query("max_liquid"))	
             return notify_fail(obj->name()+"这东西可装不了水。\n");
                  
    if(!environment(me)->query("resource/water"))
             return notify_fail("这里没有地方可以装水。\n");
             
    if( obj->query("liquid/remaining") )
		message_vision("$N将$n里剩下的" + obj->query("liquid/name") + "倒掉。\n", me, obj);
 
    if((string)environment(me)->query("resource/fill_msg"))
	            message_vision(environment(me)->query("resource/fill_msg"), me, obj);
    else message_vision("$N将$n装满。\n", me, obj);

    obj->set("liquid/type", (string)environment(me)->query("resource/water_type")?environment(me)->query("resource/water_type"):"water");
    obj->set("liquid/name", (string)environment(me)->query("resource/water_name")?environment(me)->query("resource/water_name"):"清水");
    obj->set("liquid/remaining", obj->query("max_liquid"));
    obj->set("liquid/drink_func", 0);
    obj->set("liquid/drunk_apply", (int)environment(me)->query("resource/water_apply")?environment(me)->query("resource/water_apply"):20);
    
    me->start_busy(1);
    return 1;
}



int help(object me)
{
    write(@HELP
指令格式 : fill <物品名称>
 
这个指令可以让你将空的容器装满水。
 
HELP
    );
    return 1;
}
 
