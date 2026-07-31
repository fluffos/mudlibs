#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "崖顶");
        set("long", @LONG
崖顶是一片松林，遮天蔽日，光线阴暗。你发现左边的石壁上似乎有个小
小的山洞，有几个老和尚坐在里面，面向石壁，闭目参禅，对你的到来似乎没
有任何反映。
LONG
        );

	set("outdoors", "少林寺");
	set("exits", ([ 
		"enter" : __DIR__"houshand",
		"down" : __DIR__"duanya",
	]));
        setup();
}
