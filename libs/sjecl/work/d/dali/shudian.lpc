// /dali/shudian.c 书店
// bbb 1997/06/11
// Modify By River 98/12/
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "书肆");
        set("long", @LONG
这是书店，整个房间布满了书架，书店的主人本是中原一个秀才，屡次参
加朝庭科举应试，全部落榜，深感怀才不遇。一气之下，来到这西南小国开了
这家书店为生。
LONG
        );

        set("exits", ([
              "north" : __DIR__"nanjie1",
        ]));

        set("objects", ([
                __DIR__"npc/laoxiucai" : 1,
        ]) );

        set("coor/x",-330);
  set("coor/y",-470);
   set("coor/z",-20);
   setup();

}

void init()
{
     object me = this_player();
     if(me->query_temp("xuncheng")){
      me->set_temp("dali_xc/shudian",1);
      }
}
