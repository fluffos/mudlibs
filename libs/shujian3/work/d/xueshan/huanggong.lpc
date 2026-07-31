// Room: huanggong.c

inherit ROOM;

void create()
{
	set("short", "皇宫");
	set("long", @LONG
这里是正在建筑中的新吐蕃皇宫，虽然刚刚建到一半，也可以看出规模之
大。到处是一堆堆的石料和木料，几百名戴着镣铐的囚犯在士兵的监督下和各
地聚集来的工匠在辛勤的劳作。寒冷的北风呼啸而过，卷起漫天的尘土，可工
作的人们个个却是干得满头大汗。
LONG
	);

	set("exits", ([
		"west" : __DIR__"zanpugc",
	]));
        set("objects", ([__DIR__"npc/prince" : 1,
 			 __DIR__"npc/tufanwushi" : 4,]));
	set("coor/x",-210);
  set("coor/y",120);
   set("coor/z",0);
   setup();

}
