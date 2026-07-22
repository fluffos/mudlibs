// Room: caishichang.c

inherit ROOM;

void create()
{
	set("short", "采石场");
	set("long", @LONG
在这里，平坦的草原突然隆起一座高山。脚下踩着一堆堆散碎的砾石，山脚
下老远就可以听到乒乒乓乓的声音，原来这里是个采石场。三四十个工匠正抡着
大锤打石头，不远的小丘上站着个喇嘛，监视着他们。
LONG
	);

	set("exits", ([
		"west" : __DIR__"tianyunmc",
		"eastdown" : __DIR__"cunluo1",
	]));
        set("objects", ([__DIR__"npc/seleng" : 1,]));
        set("outdoors", "雪山");
	set("coor/x",-210);
  set("coor/y",150);
   set("coor/z",0);
   setup();
}
