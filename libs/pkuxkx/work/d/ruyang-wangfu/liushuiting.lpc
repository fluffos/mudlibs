//liushouting.c -- 流水亭
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"流水亭"NOR);
  set("long", @LONG
西面假山上流下来的溪水，在这里拐了个弯，向南流到花园里去了。
岸边的草地上有个不高的青石月台，月台上有一个八角凉亭，估计是供
王爷的姬妾们玩累了，休息用的。
LONG
  );

  set("exits", ([     
      "southdown" : __DIR__"houhuayuan",   
      "northwest" : __DIR__"dajiashan", 
  ]));

  set("no_fight", 1);
  
  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}	
