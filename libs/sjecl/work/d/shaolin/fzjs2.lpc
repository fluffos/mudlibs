#include <ansi.h>
inherit ROOM;
void create()
{
       set("short", "方丈室");
       set("long", @LONG
方丈室陈设简洁，正中一几，一蒲团，一矮床。北面墙上写着大大的一
个『禅』字。一位慈眉善目的灰衣老僧正端坐于蒲团上打坐。
LONG
       );

       set("exits", ([
               "south" : __DIR__"fzjs1",
       ]));

       set("objects",([
               CLASS_D("shaolin") + "/xuan-ci" : 1,
       ]));
       setup();
}
void init()
{
        add_action("do_massage", "massage");
        add_action("do_massage", "按摩");
}
int do_massage(string arg)
{      
//    mapping fam;
    object me;
        int costj, costq,times;
        me = this_player();
        if(me->query_temp("job_name")!="服侍玄慈方丈") 
            return notify_fail("倒什么乱把这当按摩院啊？! \n");
        if (me->is_busy())
         {write("你现在正忙着呢!\n");return 1;}
        if (me->is_fighting())
         {write("你正在战斗中,无法专心干活!\n");return 1;}
        if ( !arg || arg != "方丈" )
            {   
                 message_vision("$N要给谁按摩？\n",me);
                 return 1;
             }
        costj = random((int)me->query("con")/3);
        costq = random((int)me->query("str")/3);
        times=20+random(50);
        if ((int)me->query("jingli") < costj || (int)me->query("qi") < costq)
       {
        message_vision("$N手忙脚乱，脚下一软，摔倒在地。\n",me);
        me->unconcious();
        return 1;
        }
        
        me->receive_damage("jingli", costj);
        me->add("qi", -costq);       
        if (((int)me->query_temp("mark/按摩")>times)&&(present("xuanci", environment(me))))
           {
              me->set_temp("mark/按摩完",1);
               return notify_fail(RED "玄慈方丈说道：谢谢你来服侍我，快回去休息吧(task ok)!!!"NOR);
            }  
        message_vision("$N盘膝坐下，用力按摩方丈全身，把玄慈弄的爽爽的。\n", me);
        me->add_temp("mark/按摩",1);
        
       if ( (int)me->query_skill("buddhism", 1) < 50 && random(10)>6 )
                {  write(HIM"你静坐倾听方丈诵经，对禅宗心法有些领悟!\n"NOR);
                   me->improve_skill("buddhism", (int)(me->query_skill("force",1) / 5));
                  }
          return 1;
}
