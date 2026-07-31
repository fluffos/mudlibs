// /d/zhuojun/ximen.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "西门");
	set("long", @LONG
这里是长沙的西城门，再向东走，就进入了江西地界，向西走就进入
湖北，人因为现在天下大乱所以把门的士兵对来往过路的人盘查得非常
严格。
LONG
);

set("outdoors", "changsha");
set("exits", ([
		"east" :__DIR__"xidajie1",
                "west"  :__DIR__"road1",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
