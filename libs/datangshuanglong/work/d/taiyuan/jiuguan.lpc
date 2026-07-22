// /d/taiyuan/jiuguan.c
// Room in 太原
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "小酒馆");
	set("long", @LONG
这是一家已不能再小的小酒馆，小酒馆里只有几张方桌，所卖的不
过是二锅头，花生米，豆腐干之娄，所来喝酒的也不都是穷人，买一角
酒几碟小菜，享受一下工作后乐趣。
LONG
	);
set("exits", ([
                "south" : __DIR__"dongdajie2", 
	]));
	set("objects",([
	__DIR__"npc/xiaoer2":1,
	]));
       setup();
	replace_program(ROOM);
}	
