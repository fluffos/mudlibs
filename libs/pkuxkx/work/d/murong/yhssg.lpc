//yhssg.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "还施水阁");
    set("long", @LONG
这就是举世闻名的姑苏慕容的还施水阁，这里据说有很多武林人事向
往以久的武功。只见墙上有一个书架子，上面摆满了各种武籍。西侧有个楼
梯通向观星台。
LONG
    );

    set("exits", ([
                "out" : __DIR__"yhuayuan",
                "westup" : __DIR__"ygxt",
    ]));
	set("objects",([
		__DIR__"obj/dzxy_tupu" : 1,
        ]));
         set("no_task",1);
    setup();

}
/*
void init()
{
	object me=this_player();
	if(!me->query_temp("murong/tingxiang"))
	{
		tell_object(me,"你想到自己没有征得庄主的同意,又走出了还施水阁................\n");
//		me->move("/d/murong/yhuayuan");
		return;
	}
}
*/
