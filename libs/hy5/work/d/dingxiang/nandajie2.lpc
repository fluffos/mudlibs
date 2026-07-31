// /d/yazhang/nandajie2.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
这里人山人海，你不由的放慢脚步，东西人声鼎沸，一家酒店在大
街上都能闻见酒香，西面是一家商行，进出的人不断。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "north" : __DIR__"guangchang",  
                  "south" : __DIR__"nandajie1",  
                  "east" : __DIR__"jiudian",  
                  "west" : __DIR__"shanghang",    
	]));
	set("objects",([
           __DIR__"npc/tuobayu":1,
           ]));
       setup();
	replace_program(ROOM);
}	
