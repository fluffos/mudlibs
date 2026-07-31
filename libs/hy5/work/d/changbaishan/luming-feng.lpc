
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","鹿鸣峰");
  set ("long", @LONG
鹿鸣峰又叫芝盘峰，位于之天池西北，峰顶有一草甸子，其形圆如
盘，每到严冬的季节，其它各峰已是积雪覆盖，唯有此峰还露在白雪之
外。
LONG);

  set("exits", ([ 
 "southwest":__DIR__"baiyun-feng",
 "southeast":__DIR__"pingjin-feng",
 "eastdown":__DIR__"yingzui-feng",
 "southdown":__DIR__"tianchi",
         ]));
  set("objects",([
   __DIR__"npc/tufei":1,
  ]));
  
  set("outdoors","cbs");
  
  set("valid_startroom", 1);
  setup();
 
}

void init()
{
  add_action("do_wa","wa");
}

int do_wa(string arg)
{
   object me,ob;
   me=this_player();
   if(!arg||arg!="药材")
   return notify_fail("你要挖什么？\n");
   if(me->query("sen")<20)
   return notify_fail("你挖了会，觉得精神疲惫，无法继续了。\n");
 if(me->is_busy())
 return notify_fail("你正忙着呢！\n");
 if(query("no_dig")>=10)
 return notify_fail("看来这里好象没有药材了，好象该换个地方了。\n");
   me->add("sen",-20);
 me->start_busy(1+random(2));
   if(random(100)>30)
   {
     ob=new("/obj/medicine/yaocai");
     ob->move((me));
     message_vision("$N挖到了一棵药材！\n",me);
add("no_dig",1);
     return 1;
    }
   message_vision("$N累的满头大汗，但是什么也没挖到。\n",me);
   return 1;
}


