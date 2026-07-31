// /d/zhuojun/qianzhuang.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "钱庄");
	set("long", @LONG
这里是长沙城的一家钱庄，这家钱庄已经有百年的历史了，信誉卓
著，所以在这里存钱你可以感到非常的放心。
LONG
	);
set("exits", ([
                "east"  :__DIR__"nandajie1",
	]));
	set("objects",([
	  __DIR__"npc/qian":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
