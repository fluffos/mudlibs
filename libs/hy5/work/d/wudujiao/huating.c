// Feb. 6, 1999 by Winder
inherit ROOM;
void create()
{
        set("short", "小楼");
	set("long", @LONG
这是一座精致的小楼，你走到这里，不由得眼前一耀，先是
闻到一阵幽幽的香气。
LONG
	);
	set("exits", ([ 
            "west" : __DIR__"huating1",
	]));
        set("objects", ([
		"/d/shiliang/npc/yuanchenzhi" : 1,
	]));
	set("coor/x", 1620);
	set("coor/y", -1770);
	set("coor/z", 10);
	setup();
	replace_program(ROOM);
}