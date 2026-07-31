//Write by godzilla
//Date 1999.12.23
#include <ansi.h>
int do_dujiang()
{
        object me=this_player();
        object obj=find_object("/d/bianliang/duchuan");
        int dge=me->query_skill("dodge");
        if(me->query("neili")<500)
        return notify_fail("你的内力不够，无法越过对岸。\n");
         if(me->is_busy())
        return notify_fail("你正忙着呢。\n");
        
        if(dge>=260)
        {
                if(me->query("family/family_name")=="天羽派")
                {
                        if(present("tianyu sword",me))
                        {
                                message_vision(HIY"只见$N将手中"HIC"天羽剑"HIY"往空中一抛，跟着飞跃上剑，御剑飞行，往对岸行去。\n"NOR,me);
                                tell_room(obj,HIY"忽然江面滚滚，你猛然看见"+me->name()+"御着"HIC"天羽剑"HIY"往对岸飞去。\n"NOR);
                                me->move("/d/bianliang/yellw");
                                write(HIY"你御着"HIC"天羽剑"HIY"稳稳的落下地面。\n"NOR);
                                me->start_busy(3);
                                me->add("neili",-500);
                                return 1;
                        }
                        else
                        {
                                 message_vision(HIC"$N猛然深吸一口气，双袖鼓鼓声风，犹如大鹏一般往对岸跃去。\n"NOR,me);
                                 tell_room(obj,HIC"只见"+me->name()+"在船篷上一点，借力又向对岸飞去。\n"NOR);
                                 me->move("/d/bianliang/yellw");
                                 write(HIC"你从对岸跃来，稳稳的落下地面。\n"NOR); 
                                 me->start_busy(3);
                                 me->add("neili",-500);
                                 return 1;
                        }         
                        
                }
                else
                {
                        message_vision(HIC"$N猛然深吸一口气，双袖鼓鼓声风，犹如大鹏一般往对岸跃去。\n"NOR,me);
                        tell_room(obj,HIC"只见"+me->name()+"在船篷上一点，借力又向对岸飞去。\n"NOR);
                        me->move("/d/bianliang/yellw");
                        write(HIC"你从对岸跃来，稳稳的落下地面。\n"NOR); 
                        me->start_busy(3);
                        me->add("neili",-500);
                        return 1; 
                }       
        }
        tell_object(me,"你身法还不够，可能无法越过黄河，如果想硬来请输入(tiao)。\n");
        me->set_temp("try_tiao",1);
        return 1;                       
}
int do_jump()
{
        object me=this_player();
        object obj=find_object("/d/bianliang/duchuan");
        if(!me->query_temp("try_tiao"))
        return 0;
        message_vision(HIC"$N猛然深吸一口气，使出全身功力向对岸约去。\n"NOR,me);
        tell_room(obj,HIC"只见"+me->name()+"从对岸向船跳了过来，可是到一半时，扑通一声掉进了水里，显然他功力不够。\n"NOR);
        message("channel:chat", HIW"【求救】一阵刺耳的“H～E～L～P～”声从黄河水里传来，原来是"+me->query("title")+me->name()+"\n自不量力横渡黄河，结果掉进了黄河水里，自己又不识水性只好高呼求救。\n"NOR, users() );
        me->set_temp("try_tiao",0);
        write(CYN"还好一个渔夫及时发现了你，终于把你救了起来。\n"NOR,me);
        tell_object(me,"你感觉头昏脑胀，一下失去了只觉。\n");
        me->set("water",500);
        me->unconcious();
        return 1;
}        
    
