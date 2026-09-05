//yishiting.c -- 议事厅
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"议事厅"NOR);
  set("long", @LONG
这里是汝阳王升殿议事的地方，每每汝阳王有事不能决断，需要参考
意见的时候，就将相关人等从宜宾馆请到这里，共同商议。现在这里正门
窗紧闭，不知汝阳王又在和什么人议事。东北角有个小门，可以通往后面
的承庆楼。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"huishiting",   
      "north" : __DIR__"chengqinglou", 
      "east" : __DIR__"zoulang-e2",
      "west" : __DIR__"zoulang-w2",
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
