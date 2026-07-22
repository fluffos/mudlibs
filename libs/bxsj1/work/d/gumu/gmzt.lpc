// Room: /u/xdd/gumu/gmzhongt.c
// Modify by river 98/08/29

#include <ansi.h>;
#include <room.h>;
inherit ROOM;

void create()
{
      set("short", HIG"中堂"NOR);
      set("long", @LONG
这处是古墓派弟子参见掌门之处，此刻古墓传人小龙女及神雕大侠杨过早
已名颂江湖，这对壁人不但武功已成一派宗师，两人矢志不渝之深情更令世人
倾慕不已。厅内只一张长桌，两把石椅。厅上方有一块匾额(bian).
LONG  
      );

      set("exits", ([
           "east" : __DIR__"gmht",
           "west" : __DIR__"gmqt",
           "south" : __DIR__"gmlg1",
           "north" : __DIR__"gmlg2",
      ]));

      set("item_desc", ([
          "bian" :  HIR"
             ※※※※※※※※※※※※※※※※※※※※
             ※※※※　                      ※※※※
             ※※※※    此情不悔 天荒地老   ※※※※
             ※※※※                        ※※※※
             ※※※※※※※※※※※※※※※※※※※※\n"NOR,
       ]));

      create_door("south", "石门", "north", DOOR_CLOSED);

      setup();
}

void init()
{ 
      add_action("do_jump","zong");
}

int do_jump(string arg)
{
      object me;
      me=this_player();
      if( !arg || arg!="bian") return 0;
      if(me->query_skill("dodge",1) < 101)
             return notify_fail("你功力不够，跳不上匾额。\n");
      message_vision(HIY"$N凝气守中，平空拔起数丈，轻轻落在匾额之后。\n"NOR,me);
      me->move(__DIR__"bianhou"); 
      tell_room(environment(me), me->name() + "从"HIG"中堂"NOR"跳了上来。\n", ({ me }));      
      return 1; 
}
