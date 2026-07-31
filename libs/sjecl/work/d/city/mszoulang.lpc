// mushizl.c 墓室走廊
// by Lklv 2001.9.27

inherit ROOM;

void create()
{
	set("short", "墓室通道");
	set("long", @LONG
这里是墓室里的一条通道，墙壁上很潮湿。四下里很黑，前面隐隐传来人
声。通道不是很长，有一丝光亮从远处照过来，把人的影子拖得长长的，印在
地上。
LONG
       );
	set("exits", ([
		"south" : __DIR__"fenduo2",
		"west" : __DIR__"xmushi",
    	]));
	set("objects", ([
		CLASS_D("gaibang/xqigai") : 1,
	]));
	setup();
}