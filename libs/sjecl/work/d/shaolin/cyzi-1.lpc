// cyzi-1.c
// by zqb

inherit ROOM;

void create()
{
	set("short", "菜园子");
	set("long", @LONG
这里是少林寺的菜园子，方圆有两百来亩地，寺内所需的蔬菜，大多数
都是这里产的。对于犯戒的僧人，也常被罚到这里，做些劈柴，浇地的苦役
，已赎其过。园内正有十几名僧人忙碌的耕做着，其中有几人身上居然带着
镣铐。
LONG
	);
        set("outdoors", "shaolin");

	set("exits", ([
		"south" : __DIR__"cyzi-2",
		"north" : __DIR__"xiaolu-3",
                "east" : __DIR__"cyzi-4",
	]));
        set("objects",([
		__DIR__"npc/yuan-gen" : 1,
	]));
	set("coor/x",100);
  set("coor/y",190);
   set("coor/z",110);
   setup();
}

