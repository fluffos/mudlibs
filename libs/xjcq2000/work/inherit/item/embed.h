// embed.c
#include <ansi.h>
int do_embed(object me)
{
    object where, ob;
    ob = this_object();
    where = environment(ob);
    
    if(!where->is_character() || !me || where != me || where->is_ghost()
       || me->is_ghost() || !ob->query("embedded")){
        ob->delete("embedded");
        }      
    else{
        me->receive_wound("qi", ob->query("damage")*2);
        me->receive_damage("qi", ob->query("damage")*4);
        tell_object(me, HIR "鲜血正顺着你身上的"+ob->name()+HIR"嘀嗒嘀嗒地直往下流！\n" NOR );
        tell_room(environment(me), HIR + "鲜血顺着"+me->name()+HIR"身上的"+ob->name()+HIR"直往下流！\n" NOR, ({ me }));  
        call_out("do_embed", 20, me);
        }
    return 1;
}