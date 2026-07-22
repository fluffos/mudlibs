//  xue_men.c
//  Looklove y2k 4/26

inherit ROOM;

void create()
{
      set("short", "薛府大门");
    set("long",@LONG
江湖上最有名气的薛慕华，薛神医就住在这里。年代久远的红门有的地方
已经班驳，但是没有丝毫破败的样子。一扇大门常年开着，门前挤满了前来求
医的人们，其中有不少都走南闯北的武林人士。
LONG
        );
	set("outdoors", "襄阳");
        set("exits",([
                "south"  :  __DIR__"xiaohe",
                "north"  :  __DIR__"qiant",
                ]));

        set("objects", ([
                        __DIR__"npc/jiading" : 2,
                ]));

	setup();
}
