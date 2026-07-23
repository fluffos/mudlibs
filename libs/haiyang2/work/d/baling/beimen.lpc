// baling/beimen
// Room in 龟兹 
// laowuwu 99/04/11


inherit ROOM;


void create()
{
	set("short", "北门");
	set("long", @LONG
这是巴陵北城门，因为曾经失火，到现在城墙还是黑乎乎的，因此
白纸黑字的官府告示就显得特别现眼。
LONG
	);
	
	set("exits", ([
		"south" : __DIR__"beidajie1",
                "north" : __DIR__"eroad",
	]));
    
	set("outdoors", "qiuci");
         set("objects", ([
		__DIR__"npc/bing" : 2,
                __DIR__"npc/wujiang" : 1
	]));
	setup();
	replace_program(ROOM);
}
