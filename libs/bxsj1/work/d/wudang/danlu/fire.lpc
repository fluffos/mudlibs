// fire.h Cht@SJ 2000-3-12 修改
#include <ansi.h>
int do_fire(string arg)
{
        object obj;
        object me = this_object();
        object ob = this_player();
        object *inv;
        inv = deep_inventory(me);

        if( ob->is_busy() ) 
                return notify_fail("你正忙着呢。\n");

        if( ob->is_fighting() )
                return notify_fail("你正在战斗中。\n");

        if( me->query("marks/open", 1) )
                return notify_fail("丹炉的盖子没有盖上。\n");
        
      if( !objectp( obj = present("fire", ob)))   // 判断玩家身上是否有火折。
                return notify_fail("你需要一个火折。\n");
                
        if( (int)ob->query("neili", 1)  <= 1000 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");           
                
        if( (int)ob->query("max_neili", 1)  <= 1500 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");                           

        if( me->query("marks/fired"))
                return notify_fail("柴火已经点起来了。\n");   
                
        if( !me->query("liquid/name") )
                return notify_fail("丹炉里没有水。\n");  
        if( !sizeof(inv)) 
                return notify_fail("丹炉里面什么都没有。\n");
        message_vision(HIR"\n$N点燃一堆柴火，火苗渐渐地大了起来。\n"NOR, ob);
//        destruct(obj);
        me->set("marks/fired", 1);
        me->set("marks/doing", 1);  
        ob->set_temp("doing", 1);
        remove_call_out("do_check");
        call_out("do_check", 70, me);
        return 1;
}
                                    
void do_check(object ob)
{
        object me = this_object();
        object *obj;
        int i;

        obj = deep_inventory(me);

        if ( (int)me->query("marks/doing", 1) > 0) 
        {
        message_vision("火苗渐渐地熄灭了，丹炉里面一片焦黑，$N什么丹药也没练出来。\n", ob);      
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        if( userp(ob) ) log_file("LIAN_DAN",
        sprintf("%s %s(%s) 因为煎糊丹炉炼丹失败 于 %s\n", ob->query("title"), ob->name(1), geteuid(ob), ctime(time())[4..19] ) ); 
                remove_call_out("do_ready");
                remove_call_out("do_confirm");
                me->delete("marks/doing");
                me->delete("marks/aoyao");
                me->delete("liquid/remaining");
                me->delete("liquid/name");
                me->delete("marks/fired");
                me->delete("marks/burned");
                ob->delete_temp("doing");
        }
        return;
}
