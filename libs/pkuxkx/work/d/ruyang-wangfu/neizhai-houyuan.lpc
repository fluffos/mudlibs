//neizhai-houyuan.c -- 内宅后院
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"内宅后院"NOR);
  set("long", @LONG
这里是内宅后院，东西两侧的厢房曾经分别住过小王爷和郡主。现在
，小王爷已另有府邸，搬出去住了，而郡主则不常回来住。院子的东北角
有扇门，不过总是关着的。
LONG
  );

  set("exits", ([     
      "northeast" : __DIR__"houmen", 
      "south" : __DIR__"neizhai-zhengting", 
      "east" : __DIR__"neishufang",
      "west" : __DIR__"huilang",
  ]));

  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
