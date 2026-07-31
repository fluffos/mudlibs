// /d/zhuojun/beidajie3.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
再向南走就是位处城中心的中心广场了，向北望去可以看见长沙的
北城门。西面是长沙最大一家赌场，西面一条大道直通向长沙的西门。
LONG
	);
set("outdoors", "changsha");
set("exits", ([
                "north" :__DIR__"beidajie1",
                "south"  :__DIR__"guangchang",
                "west"  :__DIR__"xidajie2",
                 "east"  :__DIR__"jinyintang",
	]));
	set("objects",([
	__DIR__"npc/qigai":1,
	]));
       setup();
	replace_program(ROOM);
}	
