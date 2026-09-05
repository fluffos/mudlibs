// Room: /clone/misc/e2.c
// Date: by jason(尔好啊) Tue Nov 17 15:39:52 2009
inherit "/biwu/biwuroom";

void create()
{
	set("short", "流云谷");
	set("long", @LONG
两座山峰之间形成的一道山谷，仿佛一个漏斗一般，吸纳着半山腰上的云雾。行走在谷中，
就仿佛行走在云层之上。这里有一面云旗，上绘九天流云。
你可以用duo这个命令来夺旗。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
		  "south" : __DIR__"e3",
		  "north" : __DIR__"e1",
		  "west" : __DIR__"e5",
		  "out" : __DIR__"eastgate",
		]));
	set("no_clean_up", 0);
	set("flag","云旗");
	set("default_flag_hp",5);
	set("flag_hp",5);	
    set("objects", ([
        "/biwu/jieshuo" : 1,
        ]));	
	setup();
}
