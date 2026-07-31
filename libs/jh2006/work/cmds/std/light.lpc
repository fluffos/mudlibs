// light.c
// by snowman@SJ 02/04/1999.

#include <ansi.h>

int main(object me, string arg)
{
    object obj, env;
    
    if (me->is_busy() || me->is_fighting()) return notify_fail("你正忙着呢。\n");

    if(!arg) return notify_fail("你要点燃什么东西？\n");
    	     
    if(!objectp(obj = present(arg, me)) )
             if(!objectp(obj = present(arg, environment(me))))
    	            return notify_fail("这。。。你好象没这东西吧？\n");
   
    if(!obj->query("light")) 
                    return notify_fail("点燃"+obj->name()+"？你是不是眼花了？\n");
    if( !obj->query("light/time")) 
                    return notify_fail(obj->name()+"已经燃烧完，不能再用了。\n");    
                
    env = environment(me);
    if( !env ) return notify_fail("这里是什么地方？\n");
    
    if( !present("fire", me))
             return notify_fail("你没有火种，怎么点燃"+obj->name()+"呢？\n");
             
    if(!obj->query("light/on")){
             if((string)obj->query("light/on_msg"))
	             message_vision(obj->query("light/on_msg"), me, obj);
             else message_vision("$N拿起火折，“啪”的一下打燃，将$n点着。\n", me, obj);

             obj->set("light/on", 1);   // turn it on now.
             obj->set("no_put", 1);
             obj->fire_decay();
             
             if((env->query("no_light")  // some special rooms.
             || (env->query("outdoors") && NATURE_D->is_night()))  // night in open air.
             && !env->query_night_light()){
    	             env->light_up();   // light up the room.
                     env->set_temp("light_id", obj); 
                     obj->set("light/env", file_name(env));
                     }
             }
    else {
    	     if((string)obj->query("light/off_msg"))
	             message_vision(obj->query("light/off_msg"), me, obj);
             else message_vision("$N将$n摇了摇，用嘴将它吹灭了。\n", me, obj);

             obj->delete("light/on");   // turn it off now.
             obj->set("light/time", obj->query("light/time"));
             
             if((string)obj->query("light/env")){
                  if(!env = find_object(obj->query("light/env")))
                       env = load_object(obj->query("light/env"));
                  if( env->query_temp("light_id") == obj){
    	               env->light_gone();   // turn light off in the room.
                       env->delete_temp("light_id");
                       }
                  }
             } 
    return 1;
}



int help(object me)
{
    write(@HELP
指令格式 : light [物品名称]
 
这个指令可以让你点燃某个可以照明的物品。

例：
    light denglong  点燃灯笼。
    light denglong  将已点燃的灯笼灭掉。
    
HELP
    );
    return 1;
}
 
