// /d/yazhang/zhubaodian.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "珠宝店");
	set("long", @LONG
这是一家专门出售贵重宝物的珠宝店。整个珠宝店设计的古香古色，
别具特色。你看这各种奇珍异宝不禁眼花缭乱，流连忘反。
LONG
	);
set("exits", ([
                 "west" : __DIR__"beidajie2",  
	]));
 set("objects",([ __DIR__"npc/zhubaoshang":1,]));
       setup();
	replace_program(ROOM);
}	
