//chengqinglou.c -- 承庆楼
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"承庆楼"NOR);
  set("long", @LONG
这里是汝阳王举办各种庆典的地方，每年朝廷例行的祭祀大典，日常
宴请洛阳地方的文武官员、乡绅巨贾等等，都在这里举行。一到那个时候
，这里总是热闹非常，洛阳本地的达官显贵，无不齐聚。但是现在，喏大
一个厅堂，就你一个人站在这里，显得空空落落的。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"yishiting",   
      "north" : __DIR__"xiaoshiqiao", 
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
