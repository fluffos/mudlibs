// /d/yazhang/datiepu.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "打铁铺");
	set("long", @LONG
这里是定襄城最大的铁匠铺，一进门就听到震耳欲聋的打铁声。从
这里出去的武器无一不是精品。在这里你可以自己打造兵器。
LONG
	);
set("exits", ([
                 "north" : __DIR__"dongdajie1",    
	]));
	set("objects",([
	__DIR__"npc/tiejiang":1,
	]));
       setup();
	replace_program(ROOM);
}
