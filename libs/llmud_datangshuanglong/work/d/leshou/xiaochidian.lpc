// /d/zhoujun/xiaochidian.c
// Room in 涿郡
// laowuwu 99/04/11
inherit ROOM;
void create()	
{
	set("short", "小吃店");
	set("long", @LONG
在小吃店买卖东西都是以价格便宜，食用方便为主，光顾这家小吃
店的人，大部分都是贫苦人，也有些江湖武林人士为了图方便到此来用
餐。
LONG
	);
set("exits", ([
                "west"  :__DIR__"nandajie2",
	]));
	set("objects",([
	 __DIR__"npc/xiaoer":1,
	 ]));
       setup();
	replace_program(ROOM);
}	
