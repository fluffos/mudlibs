//xiaojiaochang.c -- 小校场
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"小校场"NOR);
  set("long", @LONG
这里是王府内的小校场，虽是黄土地面但很平整，中间一条青石甬道
，西侧正中有个月台。每日王府的卫士都要来这里操练，王爷平时练功、
遛马，也都在这。
LONG
  );

  set("exits", ([     
//      "south" : __DIR__"jiaomen-w",   
      "north" : __DIR__"zhishichu", 
      "east" : __DIR__"weishiying-w",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
