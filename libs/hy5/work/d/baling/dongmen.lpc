// baling/dongmen
// Room in 龟兹 
// laowuwu 99/04/11
inherit ROOM;


void create()
{
	set("short", "东门");
	set("long", @LONG
这是东城门，城门正上方刻着“东门”两个楷书大字，城墙上贴着
几张官府告示。官兵们警惕地注视着过往行人，你最好小心为妙。一条
笔直的青石板大道向东西两边延伸。东边是郊外，隐约可见一片一望无
际的树林，神秘莫测。西边是城里。
LONG
	);
        set("outdoors", "qiuci");


	set("exits", ([
		"west" : __DIR__"dongdajie1",
                "east" : __DIR__"edao1",
	]));
         set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}

