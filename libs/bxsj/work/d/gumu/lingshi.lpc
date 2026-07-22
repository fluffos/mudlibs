// lingshi.c By River 98/09

inherit ROOM;
#include <ansi.h>
void create()
{
      set("short", HIC"灵室"NOR);
      set("long", @LONG
只见空空旷旷的一座大厅上并列放著五具石棺。凝神细看，见两具石棺棺
盖已密密盖著，原来是古墓派祖师林朝英和小龙女师傅的安身之处。另外二具
的棺盖(guangai)却只推上一半，也不知其中有无尸体。
LONG
        );

      set("exits", ([ 
	   "out" : __DIR__"ss5",
      ]));     

        set("objects", ([
            __DIR__"obj/fire" : 1,
        ]));
      setup();
}

void init()
{
      add_action("do_tui", "tui");      
      add_action("do_tang","tang");
}

int do_tui(string arg)
{
      object me=this_player();
      if (me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着哪！\n");
      if( arg =="guangai"){
         message_vision(YEL"$N使劲推开了棺盖。\n"NOR,me);
         me->set_temp("marks/石棺", 1);
         return 1;
      }
      return notify_fail("你要推什么？\n");
}

int do_tang(string arg)
{
      object me=this_player();       
      if (!me->query_temp("marks/石棺")) return 0;
      if (me->is_busy() || me->is_fighting())
            return notify_fail("你正忙着哪！\n");
      if ( arg =="guan"){        
         me->delete_temp("marks/石棺");
         tell_room(environment(me), me->name() +"打开棺盖后，躺了进去。\n", ({ me }));
         me->move(__DIR__"shiguan");
         message_vision(HIY"$N躺进了石棺，棺内已无转侧馀地。\n"NOR,me);
         return 1;
      }
      return notify_fail("你想躺在哪里？\n");
}
