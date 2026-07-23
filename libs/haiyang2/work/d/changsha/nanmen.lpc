// /d/zhuojun/nanmen.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "南门");
	set("long", @LONG
这是长沙的南门，再向北走就进入了岳阳城，因为现在天下大乱所
以把门的士兵对来往过路的人盘查得非常严格。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"north" :__DIR__"nandajie1",
                "south"  :__DIR__"road5",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
