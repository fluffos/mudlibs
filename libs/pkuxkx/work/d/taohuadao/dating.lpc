// taohuadao/dating 大厅

inherit ROOM;

void create()
{
        set("short", "大厅");
        set("long", @LONG
这里是桃花岛的大厅。黄药师就是在这里会客的。
LONG);
        set("exits", ([ /* sizeof() == 2 */
        "west" : __DIR__"yanbi",
        "east" : __DIR__"zoulang",
        ]));
	set("objects", ([
        CLASS_D("taohua")+"/huang" : 1,
	]));
        set("valid_startroom", 1);
	setup();
}
