
#include <ansi.h>
inherit ROOM;


void create ()
{
  set ("short","松树林");
  set ("long", @LONG
这里是一片松树林。冰雪覆盖之下，只有松树才可以如此挺拔。听
说东北三宝之一人参就在长白山，不知道能不能挖到？
LONG);

  set("exits", ([ 
 //"up":__DIR__"shanlu3",
 "down":__DIR__"shanlu2",
         ]));
   set("objects",([
      __DIR__"npc/caishenren":1,
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
