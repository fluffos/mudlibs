// /d/xingxiu/beijiang.c
// Jay 3/17/96

inherit ROOM;

void create()
{
	set("short", "伊犁");
	set("long", @LONG
这里是一座维吾尔族聚居的小镇。镇上人来人往，十分热闹。只是
他们说的话你听不懂。镇西有家小店铺，西北边人声鼎沸，好像在举行
什么比赛。东面有家院落，院门口有棵大树。北边是一家马厩。
LONG );
	set("exits", ([ 
	    "west"      : __DIR__"store",
	    "east"      : __DIR__"house",
	    "north"     : __DIR__"majiu",
	    "northwest" : __DIR__"saimachang",
	    "southeast" : __DIR__"shanjiao",
	]));
	set("objects", ([
		__DIR__"npc/woman": 2 ]) );
	set("outdoors", "xingxiu");

	setup();
}

