inherit ROOM;

#include <ansi.h>
void create()
{
  set("short",HIR"金刚伏魔圈内"NOR);
  set("long",@LONG
三棵大松树的树干上各挖了个可容身一人的大洞，有个洞口
露出黑色僧袍一角，似乎住得有人。中央是一片大草坪，中心处
光秃秃的，似乎经常受大力击打，以致寸草不生。
LONG );
     set("outdoors", "shaolin");
     set("exits",([
           "south" : __DIR__"yttl",
     ]));
 	set("objects", ([
		"/kungfu/class/shaolin/chengkun" : 1,
	]));
     setup();
}
                                                                                                                                                                                                                                                                                                                                                                                              