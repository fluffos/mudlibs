inherit ROOM;

void create()
{
	set("short", "内城");
	set("long", @LONG
这是贵阳城内城的十字街头。在东边是一个小较场，你还能听见士
兵操练的声音，西面是一座府邸，南面是一排排整齐的军房。
LONG );

	set("exits", ([
                          "north"      : __DIR__"chengmen",		
	]));

          set("objects",([
           __DIR__"npc/bing":2,
           __DIR__"npc/wujiang":1,
           ]));
 	set("outdoors", "guizhou");
	setup();
	replace_program(ROOM);
}



