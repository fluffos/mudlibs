// aoyao.h
#include <ansi.h>
int do_aoyao(string arg)
{
    object me, ob;
    me = this_object();
    ob = this_player();

    if( ob->is_busy() ) 
            return notify_fail("你正忙着呢。\n");

    if( ob->is_fighting() )
            return notify_fail("你正在战斗中。\n");

    if( !ob->query_temp("doing", 1) )
            return notify_fail("你没在熬药。\n");

    if( me->query("marks/open")) 
            return notify_fail("丹炉的盖子没有盖好。\n");

    if( !me->query("marks/burned", 1) ) 
            return notify_fail("火势还不旺盛。\n");               

    message_vision(HIY"\n$N使劲全身的力气，不断的搅拌丹炉内的药汤，累的满身是汗。\n"NOR, ob);
    me->set("marks/aoyao", 1);
    ob->start_busy(10);
    return 1;
}