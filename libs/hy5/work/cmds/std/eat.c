// eat.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj;

    if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");

    if(!arg) return notify_fail("你要吃什么东西？\n");
    if (!environment(me)) return notify_fail("目前有问题。\n");
    if (!me) return notify_fail("你断线了。\n");
if (!present(arg, me)) return notify_fail("你身上没有这样东西。。\n");
    if(!objectp(obj = present(arg, me)) ){
    	     if(objectp(obj = present(arg, environment(me))) && !obj->is_character() )
    	            tell_room(environment(me), me->name() + "盯着地上的"+obj->name() + "，咽了一口唾沫。\n",({ me }));
             return notify_fail("你身上没有这样东西。\n");
             }
    if(!obj->query("food_supply") )
             return notify_fail("看清楚点，这东西能吃吗？\n");
    if(!obj->query("food_remaining") )
	     return notify_fail( obj->name() + "已经没什么好吃的了。\n");
    if( me->query("food") >= me->max_food_capacity() )
	     return notify_fail("你已经吃太饱了，再也塞不下任何东西了。\n");
		
    me->add("food", obj->query("food_supply"));
    if( obj->query("eat_func") ) return 1;
    if( !obj ) return 1;
    
    obj->set("value", 0);
    obj->add("food_remaining", -1);
//    if((int)obj->query("food_busy"))
//             me->start_busy(obj->query("food_busy"));
            
    if( !obj->query("food_remaining") ) {
	     obj->delete_temp("apply/long");
	     if((string)obj->query("finish_msg"))
	           message_vision(obj->query("finish_msg"), me, obj);
	     else message_vision("$N将剩下的$n吃得干干净净。\n", me, obj);
	     if( !obj->finish_eat() )
		   destruct(obj);
	     } 
    else{
             if((string)obj->query("eat_msg"))
                   message_vision(obj->query("eat_msg"), me, obj);
             else message_vision("$N拿起$n咬了几口。\n", me, obj);
             }
    return 1;
}



int help(object me)
{
    write(@HELP
指令格式 : eat <物品名称>
 
这个指令可以让你吃食物。
 
HELP
    );
    return 1;
}
 
