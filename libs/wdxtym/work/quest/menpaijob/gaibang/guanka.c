inherit ROOM;

#include <ansi.h>
void create()
{
      set("short","关口");
      set("long",@LONG
这里被临时搭建了一个关卡，一个武将在指挥几个丐帮的弟子对来往游客
进行检查，百姓可以过，外族人员一律不许通过。几个外族人还正在和那
个武将理论。看来，蒙古快要进攻了，正在戒严。
LONG);
        set("valid_startroom",1);
           set("no_dazuo",1);
           set("renshu",0);
        set("objects",([
                __DIR__"huwei" : 1,
"/d/city/npc/xunbucao" : 2,
//                __DIR__"hua" : 1,
        ]));
        set("exits",([
                "south"  : "d/xiangyang/caodi6",
                "north"  : "d/xiangyang/southgate2",
                "east"  : "d/xiangyang/southgate3",
        ]));
        set("outdoors", "关口");

        setup();
}

int valid_leave(object me, string dir)
{

        if (me->query_temp("shouwei"))
        return notify_fail("你现在正在守卫，不能到处走动。\n");
        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");
        if (me->is_busy()) 
        return notify_fail("你正热闹着呢!\n");


        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_quit","halt");
        add_action("do_quit","quit");
         add_action("do_shouwei","shouwei");
}

int do_shouwei()
{
        object me=this_player();
//         me=this_player();
        object* ob;
        int i;
//        ob = users();
//        for (i=sizeof(ob); i>5; i--)
//        {
//                if (ob[i-1]->query_temp("shouwei"))
//                return notify_fail("这里最多只要五个人守。\n");
//        }
//         if (query("renshu")>=3)
//              return notify_fail("这里最多只要三个人守。\n");
            if (!(me->query_temp("xhjob_start")))
                   return notify_fail("你没有被指派到这里守卫。不要多管闲事！\n");
            if (me->query_temp("shouwei"))
                   return notify_fail("你正在守卫关卡通道。\n");
          message_vision(HIC"$N抖擞精神，开始打量身边的每一个行人。\n"NOR, me);

         me->apply_condition("xhquest", 7);
              add("renshu",1);
            me->set_temp("shouwei",1);
          return 1;
}
int do_quit(string arg)
{
        write(this_player()->query("name")+"，安心的守护！\n");
        return 1;
}
