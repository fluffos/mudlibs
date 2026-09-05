// Room: /clone/misc/w3.c
// Date: by jason(尔好啊) Tue Nov 17 15:44:29 2009
inherit "/biwu/biwuroom";

void create()
{
	set("short", "逐风岩");
	set("long", @LONG
一块巨大的岩石伸出山体，上下都是无限的虚空。岩石中部有一个圆孔，大风吹过，呜呜作响。
站立在这里，仿佛身化清风，飘飘欲飞。岩石上有一面旗帜，上绘狂风席卷大地。
你可以用duo这个命令来夺旗。
LONG
	);

	set("no_clean_up", 0);
	set("exits", ([ /* sizeof() == 3 */
		  "south" : __DIR__"w4",
		  "east" : __DIR__"w6",
		  "north" : __DIR__"w2",
		]));
	set("flag","风旗");
	set("default_flag_hp",5);
	set("flag_hp",5);	
    set("objects", ([
        "/biwu/jieshuo" : 1,
        ]));		
	setup();
}
