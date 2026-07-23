// /d/yazhang/huanggong.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "皇宫大门");
	set("long", @LONG
这里是东突厥的皇宫，皇宫金壁辉煌，朱红的宫门紧闭着，门两旁
的突厥武士横刀而立，保卫着皇宫的安全，到此处来的人都是东突厥的
高官大员。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                 "south" : __DIR__"beidajie1",
                 
	]));
	set("objects",([
	__DIR__"npc/kehan":1,
	__DIR__"npc/wujiang":3,	
	]));
       setup();
	replace_program(ROOM);
}	
