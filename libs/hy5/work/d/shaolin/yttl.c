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
           "north" : __DIR__"yttl2",
           "out" : __DIR__"fumoquan",
     ]));
 	set("objects", ([
		"/kungfu/class/shaolin/du-e2" : 1,
"/kungfu/class/shaolin/du-jie2" : 1,
"/kungfu/class/shaolin/du-nan2" : 1,
	]));
     setup();
}
int valid_leave(object me, string dir)
{
object fang;
object who;
int i;
who=me;



	if ( objectp(present("du e", environment(me))) )
		return notify_fail("少林派的人拦住了你的去路,先和我比试吧。\n");

	if ( objectp(present("du jie", environment(me))) )
		return notify_fail("少林派的人拦住了你的去路,先和我比试吧。\n");
	if ( objectp(present("du nan", environment(me))) )
		return notify_fail("少林派的人拦住了你的去路,先和我比试吧。\n");


        return ::valid_leave(me, dir);
}

                                                                                                                                                                                                                                                                                                                                                                                                    