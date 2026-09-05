// caizhu2.c:张八爷的客厅
// by wolf

inherit ROOM;

void create()
{
	set("short", "张八爷家的客厅");
	set("long", @LONG
    这里是本村最有钱张八爷的家。张八爷世代是经营玉石和黄金生意，到了他这
一代已经是第八代了。因为经营有方，所以他的生意越做越大，不过因为早年到处奔走，
张八爷身体已经不太好，所以现在把所有的生意都交给他的二儿子打理。现在他正在坐
在虎皮椅子上闭目养神，他的旁边有两个丫环。一个正在轻轻的按摩着他的双肩。另外
一个半跪着，轻轻捶着他的腿。客厅的南面是张八爷的卧室，而西面边是一间房间，东
面是一条走廊。
LONG
	);
        set("outdoors", "tzh-bang");

	set("exits", ([
		"east" : __DIR__"caizhu4",
		"north" : __DIR__"caizhu1",
		"south" : __DIR__"caizhu6",
		"west" : __DIR__"caizhu3",
	]));

	setup();
	replace_program(ROOM);
}

