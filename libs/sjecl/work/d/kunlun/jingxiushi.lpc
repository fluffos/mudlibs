inherit ROOM;

void create()
{
	set("short", "静修室");
	set("long", @LONG
这里是静修室，地下顺序地放着几个蒲团，正中烧着几柱香，轻烟袅袅升
起。几位昆仑派弟子正盘膝坐在上面打坐静修。
LONG
	);
	set("exits", ([
		"south" : __DIR__"shiqiao",
		"east"  : __DIR__"shilu1",
	]));

        set("objects", ([
		BINGQI_D("zhujian") : 2,
	]));

	setup();
}
