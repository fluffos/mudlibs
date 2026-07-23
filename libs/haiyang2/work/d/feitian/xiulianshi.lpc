//shushan2 by yushu@SHXY 2001.2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "[1;31m修练室[2;37;0m");
  set ("long", @LONG
这里是神古活心流修练室，用来练习活心流最高剑决所用，墙上面挂了几
把竹剑,你可以取一把(lianxi)练习。往右走是间休息室用来给弟子休息之用。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"qianting",
  "east" : __DIR__"xiuxishi",
]));
  set("outdoors", 2);

  setup();
//  replace_program(ROOM);
}

void init()
{
        add_action("do_lianxi", "lianxi");
}

int do_lianxi()
{
    object me=this_player();
          if(me->is_busy() )
          return notify_fail("你现在忙着呢，如何练习...\n");

        if((int)me->query_skill("parry",1)<120 )
               return notify_fail("你招架太低，无法练习。\n");
   
        if(me->query("family/family_name") != "飞天御剑流")
        {
        tell_object(me,"你不是飞天御剑流的，在这里搅和个什么。\n"); 
        return 1;
        }
        if(me->query("qi") < 100)
        {
        tell_object(me,"你还是先休息一会儿吧。\n");     
        return 1;
        }
        message_vision("$N按照师傅所指双手虚握,用力向下挥舞，练习最基本的握剑方法。\n", me);
        me->add("qi",-10);
        me->start_busy(1);
        if(me->query("feitian/chaodao")) 
        {
        tell_object(me,"你似乎不能在这里练习到什么了。\n");       
        return 1;
        }
        if((int)me->query_skill("huoxinliu-jianfa", 1) > 120){
        tell_object(me,HIW"你反复练习心里隐约对[抄刀]有了些体会！\n"NOR);
        me->add("feitian/lianxi",1);
        me->start_busy(1);
        }
        if(me->query("feitian/lianxi",1) > 200)
        {
        me->set("feitian/chaodao",1);
        tell_object(me,HIG"你反复练习终于体会到速度跟眼力的重要了，觉得可以使用[抄刀]了\n"NOR);
        me->delete("feitian/lianxi");
        }
        return 1;
}             
