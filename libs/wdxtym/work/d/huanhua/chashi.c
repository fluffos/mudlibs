//chashi.c

inherit ROOM;

void create()
{
	set("short", "茶室");
	set("long", @LONG
一进到这里就可以闻到一股茶叶的清香，墙角有个炖水的小炉，上面
的水壶已经开始往外“嘶嘶”地冒水气了。橱架上的托盘里整齐地放
着几个很漂亮的雕花茶盅。
LONG
	);

	set("exits", ([
		"east" : __DIR__"xiaoxuan",
		]));
	set("objects", ([
		  __DIR__"obj/xiangcha" : 2,
	]));


	set("coor/x",60);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-50);
	set("coor/z",0);
	set("coor/x",60);
	set("coor/y",-50);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
