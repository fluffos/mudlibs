// baling/ximen
// Room in 龟兹 
// laowuwu 99/04/11

inherit ROOM;

string look_gaoshi();

void create()
{
	set("short", "西门");
	set("long", @LONG
这是西城门，几年前曾经遭到土匪的攻打，因此显得有些破败。城
门正上方勉勉强强可以认出“西门”两个大字，城墙上贴着几张通缉告
示。这里是罪犯逃往西去的必经之地，官兵们戒备森严，动不动就截住
行人盘问。一条笔直的青石板大道向东西两边延伸。西边是郊外，骑马
的、座轿的、走路的，行人匆匆。东边是城里。
LONG
	);
        set("outdoors", "baling");

	
	set("exits", ([
		"east" : __DIR__"xidajie1",
                "west" : __DIR__"edao4",
	]));
        set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}

