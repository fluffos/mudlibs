// /d/yazhang/masi.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "马市");
	set("long", @LONG
东突厥雄霸大草原，其战马功不可未。突厥战马是马中的极品，你
走进马市，你发现这里的马都是雄骏异常。使你都不愿割舍。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                  "south" : __DIR__"dongdajie1",  
	]));
 set("objects",([
 __DIR__"npc/horse":2,
 ]));
       setup();
	replace_program(ROOM);
}	
