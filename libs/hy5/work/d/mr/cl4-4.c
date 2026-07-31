// /u/beyond/mr/cl4-4.c
// this is made by beyond
// update 1997.6.20
#include <ansi.h>
#include <room.h>
inherit ROOM;
void create()
{
         set("short",HIW"长廊"NOR);
         set("long", @long
这是一条长廊，上面画着江南秀美的工笔画。绿色的柱子朱红色的琉璃
瓦，使得你不由得对江南艺术工匠的创造惊叹不已。在长廊里面，丫鬟、家丁
们走来走去，都忙着自己的事情，西面是一间客厅，南面是长廊的延伸。
long);
         set("exits", ([
             "west" : __DIR__"keting",
             "east" : __DIR__"guifang",
             "north" : __DIR__"cl4-3",
             "south" : __DIR__"cl4-5",
]));
         set("objects",([
             __DIR__"npc/yahuan" : 1,
             ]));
         setup();
  //     replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        mapping fam;
        fam = (mapping)me->query("family");

 if (dir == "east" && objectp(present("ya huan", environment(me))))
                return notify_fail("夫人吩咐没有重要的事情不要打扰小姐休息。\n");

                  return ::valid_leave(me, dir);
} 
