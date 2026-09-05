//shanshichu.c -- 膳食处
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"膳食处"NOR);
  set("long", @LONG
王府上上下下加起来三百余口人，不时就要吃点什么，一会王妃要个
点心啦，一会王爷要个汤啦，一会卫士营添个菜啦，这里的大师傅们一天
到晚都在忙活。

LONG
  );

  set("exits", ([     
      "west" : __DIR__"neizhai-qianyuan",
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}