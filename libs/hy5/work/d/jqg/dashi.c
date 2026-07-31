// dashi.c

inherit ROOM;
#include <ansi.h>

void create()
{
      set("short", HIC"大室"NOR);
      set("long", @LONG
你举步走入一间大室，只见屋右有塌，室中凌空拉着一条长绳。窗前小小
一几，室左立着一个粗糙木橱。室内桌椅用具都用粗木搭成。
LONG
        );

      set("exits", ([
	  "west" : __DIR__"xiaoshi",
      ]));

      set("objects", ([
               //__DIR__"npc/xln" : 1,
      ]));
	
      setup();
}

void init()
{
      add_action("do_open","kai");
      add_action("do_open","open");
}

int do_open(string arg)
{
      object me,ob;
      me=this_player();
      if (me->is_busy() || me->is_fighting())
           return notify_fail("你正忙着哪！\n");
//      if (!me->query_temp("marks/银索")) return 0;
      if ( arg=="chu"){
//       if(!objectp(present("gold key", me)))        
//           return notify_fail("你没有钥匙，用什么开啊？\n");
       if(present("da tiehe", environment(me)))
           return notify_fail("你已经打开橱门了。\n");
       message_vision("$N慢慢用钥匙打开了橱门。\n",me);  
       me->delete_temp("marks/银索");
       me->start_busy(1);
       me->set_temp("marks/铁盒", 1);
       ob=new(__DIR__"obj/box");
       ob->move(environment(me));
       write("你发现橱内放着个长方形的铁盒子。\n");
       return 1;
       }
   return notify_fail("你要开什么？\n");
}
