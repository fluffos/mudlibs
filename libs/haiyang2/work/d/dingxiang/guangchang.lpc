// /d/yazhang/guangchang.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "定襄广场");
	set("long", @LONG
这里便是牙帐的中心，四条大街交汇于此。一座巍峨高大的钟楼耸
立于前，很是有些气势。每到清晨，响亮的钟声便会伴着淡淡雾气传向
牙帐的大街小巷。路口车水马龙，来往人潮不断。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"beidajie2",  
                  "south" : __DIR__"nandajie2",  
                  "east" : __DIR__"dongdajie2",  
                  "west" : __DIR__"xidajie2",    
	]));
set("objects",(["/clone/npc/man":3,]));	
       setup();
	replace_program(ROOM);
}	
