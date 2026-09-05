//qroad4.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "小路");
    set("long", @LONG
这是岸边用鹅卵石铺成的小路，两边郁郁葱葱的长满了树木.
路的西边有个小树林，不过有条水沟相隔，你可以试着跳过
去(jump)。
LONG
    );

    set("exits", ([
		"north" : __DIR__"qroad5",
		"south" : __DIR__"qroad1",
    ]));
    
    set("outdoors", "murong");
    setup();

}
void init()
{
	add_action("do_jump","jump");
}
int do_jump(string arg)
{
	object me=this_player();
	if(!arg)
	{
		message_vision("$N你要往哪里跳?\n",me);
		return 1;
	}
	if(arg!="west")
	{
		write("这边有什么好跳的！\n");
		return 1;
	}
	me->move("/d/murong/qlin1");
	message_vision("$N一提气，纵身跃过了小沟！\n",me);
	return 1;
}
