// drink.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
    object obj;
    
    if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");

    if( (int)me->query("water") >= me->max_water_capacity() )
	     return notify_fail("你已经喝太多了，再也灌不下一滴水了。\n");
    if (!environment(me)) return notify_fail("目前有问题。\n");
    if (!me) return notify_fail("你断线了。\n");

    if(!arg){
    	     obj = environment(me);
             if(!obj->query("resource/water"))
                    return notify_fail("这地方可没水。\n");
         
             if((string)obj->query("drink_msg"))
	            message_vision(obj->query("drink_msg"), me);
	     else message_vision("$N捧起一些清水，慢慢喝了下去。\n", me);
	     me->add("water", 20);
	     if( obj->query("liquid/drink_func") ) return 1;
	     return 1;
	     }
	
    else if(!objectp(obj = present(arg, me)) )
    	     return notify_fail("你身上没有这样东西。\n");

    if(!obj->query("liquid") )
             return notify_fail("看清楚点，这东西装有喝的吗？\n");
    if(!obj->query("liquid/remaining") )
	     return notify_fail( obj->name() + (obj->query("liquid/name") ? "已经被喝得一滴也不剩了。\n":"是空的。\n"));
			
    me->add("water", 10+((int)obj->query("liquid/drunk_apply")?obj->query("liquid/drunk_apply"):20));
     
    obj->set("value", 0);
    obj->add("liquid/remaining", -1);
    
//    if((int)obj->query("liquid/busy"))
//             me->start_busy(obj->query("liquid/busy"));
    
    if((string)obj->query("drink_msg"))
             message_vision(obj->query("drink_msg"), me, obj);
    else message_vision("$N拿起$n咕噜噜地喝了几口" + obj->query("liquid/name")+ "。\n", me, obj);
              
    if( !obj->query("liquid/remaining") ){
    	     if((string)obj->query("finish_msg"))
	           write(obj->query("finish_msg"));
             else write("你已经将" + obj->name() + "里的" + obj->query("liquid/name")+ "喝得一滴也不剩了。\n");
             }

    if( obj->query("liquid/drink_func") ) return 1;
    if (!obj) return 1;

    switch(obj->query("liquid/type")) {
	     case "alcohol": me->apply_condition("drunk",(int)me->query_condition("drunk")+ (int)obj->query("liquid/drunk_apply")); break;
	     case "xx_poison": me->apply_condition("xx_poison",(int)me->query_condition("xx_poison")+ (int)obj->query("liquid/drunk_apply")); break;
	     
	}
    return 1;
}



int help(object me)
{
    write(@HELP
指令格式 : drink [物品名称]
 
这个指令可以让你喝饮水。

例：
    drink jiudai.
    
    drink.   ( 如果你所在的地方有水源的话)。
     
HELP
    );
    return 1;
}
 
