

inherit ROOM;


void create()
{
	set("short", "奉节县");
	set("long", @LONG
这是一条官路。路上人来人往，热闹非凡。在往南走就到巴陵的北
门了。向东则是通往向北是通的官道，东北方向有一条小土路。
LONG
	);
	
	set("exits", ([
		"north" : __DIR__"anle",
                "south" : __DIR__"beimen",
                "east" : __DIR__"eroad1",
                "northeast" : __DIR__"tulu1",
	]));
    
	set("outdoors", "qiuci");
	setup();
	replace_program(ROOM);
}
