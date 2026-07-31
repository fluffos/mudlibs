#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	  set("short", "广场西");
	  set("long",@long
这里是一个平平开阔的大广场，广场上有昆仑派的弟子在习武，东面仍然
是广场，西面过去就是悬崖了，北面是下山的路。
long);
	  set("exits",([
             "northeast" : __DIR__"shanlu04",
             "east" : __DIR__"guangchang",
          ]));
          set("objects",([
	       __DIR__"npc/kl-dizi3" :  1,
          ]));

          set("outdoors", "昆仑");
          setup();
}
