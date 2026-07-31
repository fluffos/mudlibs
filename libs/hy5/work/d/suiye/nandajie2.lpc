// "suiye"/nandajie2
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "南大街");
	set("long", @LONG
这里的路很窄，仅能容一匹马车经过，长长的道路贯穿南北，一个
小贩在热心的叫卖着。东面是一家妓院。几个漂亮的女子在门边和武士
打情骂俏，对面却静悄悄的，原来是一家书店。
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"nanchengmen",
		"north" :  __DIR__"nandajie1",
                "east"  : __DIR__"jiyuan",
                "west"  :__DIR__"shudian",
	]));
 set("objects",([ __DIR__"npc/jianke":1,]));
       setup();
	replace_program(ROOM);
}	
