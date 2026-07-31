// /d/yazhang/beidajie2.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
你挤过人群，走在青石的街道上，在向北走就是牙帐的十字街口，
东面一家珠宝店，西面传来一五一十的数钱声，那里是方圆几十里内最
大的一家钱庄。
LONG);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"beidajie1",  
                  "south" : __DIR__"guangchang",  
                  "east" : __DIR__"zhubaodian",  
                  "west" : __DIR__"qianzhuang",    
	]));
	set("objects",([
           __DIR__"npc/chunyuwei":1,
           ]));
       setup();
	replace_program(ROOM);
}	
