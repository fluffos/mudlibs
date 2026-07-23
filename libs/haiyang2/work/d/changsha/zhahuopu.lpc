// /d/zhuojun/zhahuopu.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "杂货铺");
	set("long", @LONG
在这个杂货铺虽然不是很大，但是货物却很齐全，据说这里的老板
手眼通天，什么样的东西都能买到，如果你想得到什么世间稀奇的东西，
尽管放心找他好了。
LONG
	);
set("exits", ([
                "north"  :__DIR__"dongdajie1",
	]));
	set("objects",([
	  __DIR__"npc/li":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
