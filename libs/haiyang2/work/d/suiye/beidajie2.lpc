// "suiye"/beidajie2
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
路还是那么窄，但人渐渐多了起来，一个卖艺的人在努力吆吆喝着。
东面是打铁铺。西面是一家杂货铺。
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south" : __DIR__"zhongxinguanchang",
		"north" :  __DIR__"beidajie1",
                "east"  : __DIR__"datiepu",
                "west"  :__DIR__"zahuopuu",
	]));
 set("objects",([ __DIR__"npc/yiren":1,]));
       setup();
	replace_program(ROOM);
}	
