// embed.c
#include <ansi.h>

int do_embed(object me)
{
    	object ob;
    	ob = this_object();
  
    	if( !ob->query("embedded") || !me) return 0;
    
    	if(environment(ob) != me 
       	|| me->is_ghost() 
       	|| !me->query_temp("embed")){
       		tell_room(environment(me), "喔哦！\n" , ({ me }));  
            	delete("embedded");
              	return 0;
        }
        
    	me->receive_wound("qi", ob->query("damage"), "身中"+ob->name()+"而");
        tell_object(me, HIR "鲜血正顺着你身上的"+ob->name()+HIR"嘀嗒嘀嗒地直往下流！\n" NOR );
        tell_room(environment(me), HIR + "鲜血顺着"+me->name()+HIR"身上的"+ob->name()+HIR"直往下流！\n" NOR, ({ me }));  
        call_out("do_embed", 15+random(10), me);
        
    	return 1;
}
