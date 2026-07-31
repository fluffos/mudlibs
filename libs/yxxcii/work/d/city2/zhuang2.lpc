//Design By Robert 蝴蝶君 email:stcoolman@21cn.com

inherit ROOM;

void create()
{
	set("short", "小路");
	set("long", @LONG
你走在一条小路上。路面泥泞不堪，隐约留下几个路人留下的脚印，
一个凶神恶煞的大汉坐在路边，正凶狠的盯着你。据说这里经常有盗贼土
匪出没，还是快些离开的好。前方隐约有房屋可见。
LONG
);
	set("exits", ([
		"south" : __DIR__"zhuang1",
		"north" : __DIR__"zhuang3",
	]));
	set("objects", ([
		"/d/wudang/npc/tufei1" : 1,
	]));

	set("outdoors", "city2");
	setup();
	replace_program(ROOM);
}



