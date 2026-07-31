// Modify By River 98/12
inherit ROOM;

void create()
{
        set("short", "书房");
	set("long", @LONG
这里就是玉虚观内的书房。看不出这一个小观内竟然有如此多的道家经典。
房间四周都是大书架，上面放满了书，书房中间有张桌子和几张椅子，供观内
道姑使用。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
	    "east" : __DIR__"yuxuguan",
        ]));
       
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
