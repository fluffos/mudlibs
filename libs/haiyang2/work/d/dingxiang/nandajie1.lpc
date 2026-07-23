// /d/yazhang/nandajie1.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
这里是高原云集之城两旁店铺林立，东面是一家花粉店，专门是一
些女儿家用的胭脂花粉，几类首饰。西面是一家裁缝店。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"nandajie2",  
                  "south" : __DIR__"nanmen",  
                  "east" : __DIR__"huafendian",  
                  "west" : __DIR__"chaifengdian",    
	]));
       set("objects",([
         __DIR__"npc/jiesheshuai":1,
         ]));
       setup();
	replace_program(ROOM);
}	
