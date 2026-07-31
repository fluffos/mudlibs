// by mayue

inherit ROOM;

void create()
{
	set("short", "石隙");
	set("long", @LONG
这里是一道岩石的缝隙，窄得要人侧身挤过。你沿着曲折的岩缝
向前摸去，四周黑漆漆的，只有脚下的砂石发出轻微的声响。
LONG
	);
//       set("outdoors", "wudujiao");

	set("exits", ([
//		"eastup" : __DIR__"shixi",
              "down" : __DIR__"baidu2",
 		"westdown" : __DIR__"mishi",
//		"north" : __DIR__"wandu2",
	]));
        set("objects", ([
//                "/d/npc/guojing": 1,
	]));
    

	setup();
	replace_program(ROOM);
}

