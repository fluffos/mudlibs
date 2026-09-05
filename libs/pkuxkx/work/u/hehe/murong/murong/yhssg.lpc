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
往以久的武功。只见墙上有一个书架子，上面摆满了各种武籍。
LONG
    );

    set("exits", ([
		"out" : __DIR__"yhuayuan",
    ]));
	set("objects",([
		__DIR__"obj/dzxy_tupu" : 1,
        ]));
	set("no_get",1);
	set("no_fight",1);
	set("no_steal",1);
    set("outdoors", "murong");
    setup();

}
void init()
{
	object me=this_player();
	if(!me->query_temp("murong/tingxiang"))
	{
		me->move("/d/murong/yhuayuan");
		message_vision("$N没有征的庄主的同意居然就感进还施水阁，真是大胆！\n",me);
		message_vision("$N感到自己被丢出了还施水阁................\n");
		return;
	}
}
