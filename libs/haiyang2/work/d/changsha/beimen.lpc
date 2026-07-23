// /d/zhoujun/beimen.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "北城门");
	set("long", @LONG
这里是长沙城的北城门，向南望去车水马龙人来人往好不热闹，因
为现在天下大乱所以把门的士兵对来往过路的人盘查得非常严格。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"dadao1",
                "south"  :__DIR__"beidajie1",
	]));
        set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));

       setup();
	replace_program(ROOM);
}	
