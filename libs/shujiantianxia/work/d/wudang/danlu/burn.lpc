// burn.h Cht@SJ 2000-3-12 修改
#include <ansi.h>
int do_burn(string arg)
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

        if( me->query("marks/open", 1) )
                return notify_fail("丹炉的盖子没有盖上。\n");

        if( !me->query("marks/fired", 1) )
                return notify_fail("丹炉内还没有生火，你怎么能够使柴火燃烧起来？\n");

        if( me->query("marks/burned", 1))
                return notify_fail("丹炉里的火焰已经很大了，不用再加大火力了。\n");

        if( !arg || arg =="" || arg != "coal")
                return notify_fail("你要燃烧什么东西？\n"); 
                
        if( (int)ob->query("neili", 1)  <= 1000 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");           
                
        if( (int)ob->query("max_neili", 1)  <= 1500 )
                return notify_fail("你的内力不够，点着了火也拉不动风箱。\n");                           

        if( arg =="coal") 
        {
                message_vision(HIC"\n$N使劲地拉动风箱，丹炉里冒出阵阵青烟。\n"NOR, ob);
                remove_call_out("do_ready");
                call_out("do_ready", 30, me);
                me->set("marks/burned", 1);
                ob->add("neili", -1000);
                ob->add("jingli", -500);
                ob->start_busy(15);
                return 1;
        }
}

void do_ready(object ob)
{
        object me = this_object();
        message_vision(HIW"\n火势渐渐大了起来，一股浓重的草药味道扑鼻而来。应该熬药了。\n"NOR, ob);
        ob->start_busy(2);
        remove_call_out("do_confirm");
        call_out("do_confirm", 30+random(10), me);
        return;
}

void do_confirm(object ob)
{
        object me = this_object();

        if( me->query("marks/aoyao", 1) ) 
        {
                remove_call_out("confirm");
                remove_call_out("ready");
                message_vision(HIR"\n药快熬好了，赶紧灭火吧！\n"NOR, ob);
                remove_call_out("do_check");
                call_out("do_check", 70, me);
                me->delete("marks/burned");
                ob->set_temp("done", 1);
        }
        else 
        {
                write(HIY"一股焦糊味道扑鼻而来。\n"NOR, ob);
                ob->start_busy(7);
                remove_call_out("do_failed"); 
                call_out("do_failed", 7, me);
        }
        return;
}

void do_failed(object ob)
{
        object me = this_object();
        object *obj;
        int i;

        obj = deep_inventory(me);
        if( !sizeof(obj) )      return;
        for(i=0; i<sizeof(obj); i++) {
        destruct(obj[i]);
        }
        message_vision("丹炉里面一片焦黑，$N什么丹药也没练出来。\n", ob);
        if( userp(ob) ) log_file("LIAN_DAN",
        sprintf("%s %s(%s) 因为煎糊丹炉炼丹失败 于 %s\n", ob->query("title"), ob->name(1), geteuid(ob), ctime(time())[4..19] ) ); 
        remove_call_out("do_ready");
        remove_call_out("do_confirm");
        me->delete("marks/aoyao");
        me->delete("marks/open");
        me->delete("marks/fired");
        me->delete("marks/doing");
        me->delete("liquid/remaining");
        me->delete("liquid/name");
        me->delete("marks/burned");
        ob->delete_temp("doing");
        return;
}
