//Zine skf大清 

inherit ROOM;
#include "/d/city/duo_path.h"
void create()
{
	set("short", "林间小路");
	set("long", @LONG
这是一条林间小路，因为扬州城的老百姓多数逃难了，这里白骨幽幽，显得格
外的恐怖。前方有两条道，全部通向长江天险。东北面是一条河流，东南面是一处
小山。
LONG);

	set("exits", ([
		"southeast" : __DIR__"duo-path2b",
		"northeast" : __DIR__"duo-path2a",
        "out" : __DIR__"qingjunying",
	]));

	set("no_task",1);
    set("outdoors", "city");
	setup();
}

void init()
{
    object me=this_player();
    int t=time()-(int)me->query_temp("skf/qingstart");
	set("no_die",1);
	this_player()->listen_to_die(this_object());
    if (!wizardp(me)&&userp(me) && t>600)
    {
        tell_object(me,"多尔衮已经不耐烦了，你还是赶紧回去吧！\n");
        me->move(__DIR__"qingjunying");
    }
    return;
}

