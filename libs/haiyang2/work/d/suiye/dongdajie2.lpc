// "suiye"/dongdajie2
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "东大街");
	set("long", @LONG
路更宽了，熙熙攘攘的人们出入着酒楼，还有一些江湖豪客从东城
门走来，好多无所事事的人也在这摇晃者，南面则是一家民宅。
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"west" : __DIR__"dongdajie1",
		"north" :  __DIR__"jiulou",
                "east"  : __DIR__"dongchengmen",
                "south"  :__DIR__"minzhai",
	]));
set("objects",(["/clone/npc/man":1,]));
       setup();
	replace_program(ROOM);
}	
