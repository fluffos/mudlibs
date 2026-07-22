// /d/zhuojun/tiejiangpu.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "铁匠铺");
	set("long", @LONG
据叫这个铁匠铺的铁匠是铸大师欧治子的后人，他打制的兵器经久
耐用，锋利异常所以不少知名武林人士不惜重金千里迢迢来此订制所需
兵器。
LONG
	);
set("exits", ([
		"east" :__DIR__"beidajie1",
	]));
        set("objects",([
                __DIR__"npc/tiejiang" : 1,
        ]));

       setup();
	replace_program(ROOM);
}	
