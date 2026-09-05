// Room: /clone/misc/eaststreet.c
// Date: by jason(尔好啊) Tue Nov 17 15:40:17 2009
// edit: by zine Aug 21 2010
inherit "/biwu/biwuroom2";

void create()
{
	set("short", "东大街");
	set("long", @LONG
这里是古襄阳的东大街，一条笔直的长街直贯东西。千年的风霜改变了她的
容颜，街边一个个残破的店铺仿佛向你叙述着一个个不同的传奇。
LONG
	);
	set("exits", ([ /* sizeof() == 6 */
		"east" : __DIR__"eastgate1",
	    "west" : __DIR__"eastdoor",
        "north" : __DIR__"estreet1",
   	    "south" : __DIR__"estreet2",
	]));
	set("objects", ([("/biwu/xy/npc/yexingren") : random(2),
    ]));
	set("no_clean_up", 0);
	setup();
}
