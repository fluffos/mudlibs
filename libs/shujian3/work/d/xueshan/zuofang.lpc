// Room: zuofang.c

inherit ROOM;

void create()
{
	set("short", "吐蕃织造作坊");
	set("long", @LONG
由于吐蕃国内盛产优质皮毛，所以丝毛手工艺品业发达。这里是吐蕃国官
办的作坊，无论从规模还是技术都是一流的。作坊内长年点着粗大的牛油蜡烛，
房间的一角加工好的皮毛堆得象小山一样，几十名女工低头飞快的织着花色不
同的毛毯，手法娴熟，其中有不少还是十几岁的孩子。一个监工模样的人来回
走动巡视着。
LONG
	);

	set("exits", ([
		"east" : __DIR__"jiedao2",
	]));
        set("no_sleep_room",1);
        set("objects", ([__DIR__"npc/worker" : 3,
			__DIR__"npc/jiangong" : 1
	]));
	set("coor/x",-230);
  set("coor/y",110);
   set("coor/z",0);
   setup();
}
