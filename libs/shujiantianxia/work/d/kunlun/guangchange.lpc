#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
	  set("short", "广场东");
	  set("long",@long
这里是一个平平开阔的大广场，广场上有昆仑派的弟子在习武，西面仍然
是广场，东面过去就是悬崖了，北面是下山的路。
long);
	  set("exits",([
               "northwest" : __DIR__"shanlu04",
               "west" : __DIR__"guangchang",
          ]));
          set("objects",([
                CLASS_D("kunlun") + "/yulingzi" : 1,
		__DIR__"npc/kl-dizi3" :  2,
          ]));
          set("outdoors", "昆仑");
          setup();
}
