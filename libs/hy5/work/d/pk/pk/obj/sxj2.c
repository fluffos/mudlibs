#include <ansi.h>

inherit ITEM;

void init()
{
       add_action("do_start", "start");
       add_action("do_stop", "stop");
}


void create()
{
       set_name(HIW"专业摄像机"NOR, ({"she xiangji", "xiangji"}));
       if (clonep())
               set_default_object(__FILE__);
       else {
        set("long", "这是一台专业摄像机,功能齐全,摄像效果特别好。\n");
               set("value", 1000000000);
               set("unit", "台");
               set("no_get", "小朋友别乱动。\n"NOR);
       set("env/invisibility",10);
        set("invisibility",10);
        set("no_clean_up",1);

               set_weight(999999999);
       }
}

int do_start(string arg)
{
       object target, where, npc, me;
       me = this_player();
       
       if( wiz_level(me) < 3)
                return notify_fail("这么贵重的东西，你还是别碰为好。\n"); 
    
       if( me->is_busy() || me->is_fighting())
          return notify_fail("你正忙着呢。\n");

       if( !arg)
          return notify_fail("你要看谁呢。\n");

       if (objectp(target = LOGIN_D->find_body(arg))) 
            where = environment(target);
       else return notify_fail("没有这个人耶。。。\n");
       
       if (!where) return notify_fail("这个人在虚无飘藐间，找不到他。\n");
//        if( !environment(me)->query("bwdhpk"))
//        return notify_fail("此人不在比赛。\n");       

       
       if (wizardp(target)) return notify_fail("你想偷窥高级领袖，不要命了？\n");

       if (target==me) return notify_fail("自己偷窥自己？\n");

       if(objectp(npc = me->query_temp("jingtou2")))
          return notify_fail("你已经在使用摄像机中。\n");
          
       message_vision(HIY"\n$N大声说道：各单位注意，镜头对准"+target->name()+HIY"，开拍！\n\n" NOR, me);

     npc = new(__DIR__"jingtou2");
       npc->do_setup(me, target);
       me->set_temp("jingtou2", npc);
       me->start_busy(1);
       add("used", 1);
       return 1;
}


int do_stop()
{
        object npc, me;
        me = this_player();
        
        if(!me->query_temp("jingtou2"))
          return notify_fail("你还没打开摄像机呢。\n");

        npc = me->query_temp("jingtou2");
        if(objectp(npc))
           npc->do_remove();
        message_vision(HIC"\n$N关上了摄像机，说道：还算不错，收工。\n\n" NOR, me);
        me->delete_temp("jingtou2");
        me->start_busy(1);
        return 1;
}


