// Room: /d/shaolin/shulin1.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "松树林");
	set("long", @LONG
这是一片松树林。几十丈高的大松树簇在一块，密实的枝叶象一蓬蓬巨
伞般伸向天空，把阳光遮得丝毫也无。尺把厚的松针积在地上，一脚踩下去
，半天拔不出来。
LONG
	);

	set("exits", ([
		"east" : __DIR__"shulin"+(random(10)+2),
		"south" : __DIR__"shanlu8",
		"west" : __DIR__"shulin2",
		"north" : __DIR__"shulin"+(random(10)+2),
	]));

//      set("no_acc_drop",1);
	set("outdoors", "shaolin");
	set("objects",([
		__DIR__"obj/fake-gold" : 1,
	]));
	set("coor/x",70);
  set("coor/y",520);
   set("coor/z",160);
   setup();
}


