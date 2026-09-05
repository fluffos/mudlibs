//shuzhai.c -- 书斋
//Zone: 汝阳王府
//Created by ddid
//2009-6-1

#include <ansi.h>
inherit ROOM;
void create()
{
  set("short", HIC"书斋"NOR);
  set("long", @LONG
一张宽大的紫檀书案摆在正中，两侧各立着一个高大的书架，书架里
零零碎碎地塞着几本图册。书案背后，一幅巨大的中原地图，悬在正中的
墙上，图上详细地标注着“少林”、“武当”、“峨嵋”、“明教”等中
原武林门派的地点及活动范围。地上有一口大缸，似乎有更多的图塞在这
个缸里。这里是王爷处理公务的地方，但王爷平时喜欢骑马打猎，这里就
很少来。

LONG
  );

  set("exits", ([     
      "south" : __DIR__"yibinguan",   
      "north" : __DIR__"jingtang", 
  ]));

//  set("outdoors", "luoyang");
  setup();
  replace_program(ROOM);
}
