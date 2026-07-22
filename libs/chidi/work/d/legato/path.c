#include <room.h>
inherit ROOM;

void create()
{
      set("short","幽径");
      set("long",@LONG
这是通往花园的一条小路,路面有上等的汉白玉铺成
两旁是茂盛的树阳光透过树叶之间的缝隙照射到路面上
风吹过,树叶摇动,路面上便跳跃着晶莹剔透如珍珠
般的光芒.
LONG);
      set("outdoors", "xx");
      set("exits",([ /* sizeof() == 2 */
          "south" : __DIR__"lingjian",
          "north" : __DIR__"bank",
      ]));
      setup();
}

