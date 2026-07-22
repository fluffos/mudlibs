// Room: /d/city/dongdajie3.c

inherit ROOM;

void create()
{
	set("short", "东大街");
	set("long", @LONG
这是一条宽阔的青石板街道，向东西两头延伸。东边不时地传来朗朗的书
声，西北边是一个热闹的广场，南边则是一家古香古色的店铺，里边不时传出
用乐器吹奏的曲调。
LONG
	);
        set("outdoors", "扬州");

	set("exits", ([
		"east" : __DIR__"dongdajie2",
		"south" : __DIR__"yueqidian",
	        "west" : __DIR__"guangchangnan",
		"north" : __DIR__"guangchangdong",
	]));

	set("coor/x",120);
  set("coor/y",-20);
   set("coor/z",0);
   set("incity",1);
	setup();
}

