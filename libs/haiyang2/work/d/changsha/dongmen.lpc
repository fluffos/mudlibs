// /d/zhuojun/dongmen.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "天心阁");
	set("long", @LONG
天心阁则是长沙古城的标志。城楼始建于明代，重修于清乾隆
时期；建国后再修。昔日对联"四面云山都入眼，万家烟火总关心"
，即为建阁之初衷。传说此处地脉隆起，有文运昌隆的祥兆。楼阁
三层，碧瓦飞檐，朱梁画栋，基址占着城区最高地势，加之坐落在
30多米高的城垣之上，近有妙高峰为伴，远望岳麓山为屏，更显挺
峭、峻美，成为长沙古城的标志。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
		"east" :__DIR__"eroad1",
                "west"  :__DIR__"dongdajie1",
	]));
       set("objects",([
                __DIR__"npc/guanbing" : 2,
                __DIR__"npc/wujiang" : 1,
        ]));
       setup();
	replace_program(ROOM);
}	
