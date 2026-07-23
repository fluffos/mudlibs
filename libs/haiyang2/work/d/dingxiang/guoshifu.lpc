// /d/yazhang/guoshifu.c
// Room in 牙帐
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "国师府");
	set("long", @LONG
这里是东突厥国师的府地，门上的扁是皇上御赐的，你抬头望去，
“国师府”三个大字映入眼帘。
LONG
	);
set("outdoors", "dingxiang");
set("exits", ([
                   "south" : __DIR__"xidajie2",  
"northwest":__DIR__"yizhan",
	]));
	set("objects",([
	__DIR__"npc/bi":1,
	]));
       setup();
	replace_program(ROOM);
}	
