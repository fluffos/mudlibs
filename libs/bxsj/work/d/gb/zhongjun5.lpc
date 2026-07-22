inherit ROOM;

#include "zhongjun.h"

void create()
{
	set("short", "中军大帐");
	set("long", @LONG
这是蒙古大军的中军大帐，远处隐隐传来号角和战马的嘶鸣之声。这里灯
火通明，几明虎背熊腰的大汉伺立在下首。
LONG);
	set("exits", ([
        	"south" : __DIR__"zhongjun4",
        ]));
	set("objects", ([
        	__DIR__"npc/yuanbing-shiwei" : 2,
     		__DIR__"npc/yuanshuai" :1,
	]));
	setup();
}

int valid_leave(object me, string dir)
{
	object ob;
	ob = present("zhongjun shiwei",environment(this_player()) );
	if(ob)
    		return notify_fail("中军侍卫一把将你拦住：哪里跑！\n" );
        return ::valid_leave(me, dir);
}
