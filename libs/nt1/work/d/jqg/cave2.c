// cave2.c 山洞
inherit ROOM;
#include <ansi.h>
void create()
{
          set("short","山洞");
          set("long",@LONG
山洞里蜿蜒崎岖，绵延向下，由于鳄潭水气蒸浸，洞中潮湿滑溜，腥臭难
闻。令人不寒而立。遑论是在毫无亮光的情况下，平添几份阴森的感觉。洞中
极窄，根本站不起身来。
LONG
);
          setup();
          
}

void init()
{
          add_action("do_climb",({"climb", "pa", "zuan"}));
}

int do_climb(string arg)
{
       object me = this_player();
       if(!arg || arg !="down") 
               return notify_fail("你朝哪里爬？\n");
       if (me->is_busy() || me->is_fighting())
               return notify_fail("你正忙着哪！\n");
       if ( arg=="down"){
       if (random(me->query_str()) >= 20){
               message("vision", me->name() + "运劲双肩，手脚兼用，向前钻去，但洞道确实太小，很难前行。\n", environment(me), ({me}));
               tell_object(me,"你运劲双肩，手脚兼用，向前钻去，但洞道确实太小，很难前行。\n"NOR);
               me->start_busy(10);
               remove_call_out("out1");
               call_out("out1", 10, me);
               return 1;
       }
       else {
               message("vision", me->name() + "弓起身，慢慢地屈膝爬行前进。\n", environment(me), ({me}));
               tell_object(me,"你弓起身，慢慢地屈膝爬行前进。\n");
       }
       tell_object(me,HIW"\n你眼前霍然一亮，山洞越来越大，地下越来越平整。\n"NOR);
       me->move(__DIR__"cave3");
       me->start_busy(1);
       message("vision", me->name() + "从洞口钻了出来。\n", environment(me), ({me}));
       return 1;
       }
       return notify_fail("你朝哪里爬？\n");
}

void out1(object me)
{
       tell_object(me,"\n你只觉得整个身体几乎被嵌在洞中，只能弓起身，慢慢地屈膝爬行前进。\n"NOR);
       me->start_busy(10);
       remove_call_out("out");
       call_out("out", 10, me);
}

void out(object me)
{
       tell_object(me,HIW"\n你眼前霍然一亮，山洞越来越大，地下越来越平整。\n"NOR);
       me->move(__DIR__"cave3");       
       message("vision", me->name() + "从洞口钻了出来。\n", environment(me), ({me}));
}
