// "suiye"/beidajie1
// Room in 碎叶
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short", "北大街");
	set("long", @LONG
这里的路很窄，仅能容一匹马车经过，长长的道路贯穿南北，一个
小贩在热心的叫卖着。东面是钱庄。西面是驿站。
LONG
	);
set("outdoors", "suiye");
set("exits", ([
		"south":__DIR__"beidajie2",
		"north":__DIR__"beichengmen",
                "east":__DIR__"qianzhuang",
                "west":__DIR__"yizhan",
	]));
set("objects",([
"/clone/npc/man":1,
"/clone/misc/dache":1,	
	]));	
       setup();
	replace_program(ROOM);
}	
