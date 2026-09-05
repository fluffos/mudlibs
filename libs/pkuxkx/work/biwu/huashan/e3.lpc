// Room: /clone/misc/e3.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
inherit "/biwu/biwuroom";

void create()
{
	set("short", "朝阳峰");
	set("long", @LONG
这是一座孤立的山峰，位于群峰的最东边，每当日出之时，这里最先看到阳光。其时霞光如雨，
紫气东来。山峰上有一杆日旗，上绘金乌逐日。
你可以用duo这个命令来夺旗。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		  "south" : __DIR__"e4",
		  "north" : __DIR__"e2",
		  "west" : __DIR__"e6",
		]));
	set("no_clean_up", 0);
	set("flag","日旗");
	set("default_flag_hp",5);
	set("flag_hp",5);	
    set("objects", ([
        "/biwu/jieshuo" : 1,
        ]));		
	setup();
}
