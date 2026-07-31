//Design By Robert 蝴蝶君 Email:stcoolman@21cn.com

inherit ROOM;
void create()
{
	set("short", "听泉亭");
	set("long", @LONG
沿石梯向下，就是海棠溪。这里是溪上的听泉亭，四顾山环水绕，古
藤蔓蔓，飞泉溅落池中，如琴弦轻拨，如珠落玉盘，清绝幽绝。
LONG
);
	set("outdoors","qingcheng");
	set("exits", ([
		"westup"   : __DIR__"sandaoshi",
	]));
	set("objects", ([
		CLASS_D("qingcheng") +"/luo" : 1,
	]));
	setup();
	replace_program(ROOM);
}

