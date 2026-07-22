

inherit ROOM;
#include <room.h>

void create()
{
      set("short","客房");
      set("long",@LONG
这是招待客人休息的房间，靠墙的地方是一张大床，屋子的中间的
香炉正缓缓的散发出袅袅香气，傍边的桌子上摆放着笔墨纸砚，整
间屋子简朴却有一种书香气.
LONG);
         
         set("exits",([ /* sizeof() == 1 */
          "east"    : __DIR__"bank",
         
      ]));
      set("valid_startroom","1");
      set("sleep_room","1");
      setup();
}

