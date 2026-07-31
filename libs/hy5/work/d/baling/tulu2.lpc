
inherit ROOM;


void create()
{
	set("short", "大足县");
	set("long", @LONG
这是一条尘土飞扬的小路，不过在以前这里是连接九江和巴陵的
唯一路径。现在由于已经修建其它的道路，自然走的人也就少了。这里
的行人稀少，路旁有几个废弃的房屋。
LONG);
	
	set("exits", ([
		"north" : __DIR__"tulu3",
		"south" : __DIR__"tulu1",
                "southwest" : __DIR__"anle",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
