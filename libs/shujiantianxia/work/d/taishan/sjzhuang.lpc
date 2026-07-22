// Room: /d/taishan/sjzhuang.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIY"单家庄"NOR);
        set("long", @LONG
你走到一座高宅大院的门口，大门开着，门前左右有两个石狮子，四五级
青石台阶上是两扇钉满铜钉的大门。看得出这里是当地大豪的住所。门口正中
央高悬着一块黑底金字的大匾“单家庄”。
LONG
        );
        set("exits", ([
              "south" : __DIR__"shulin1",              
        ]));

        set("objects",([
                __DIR__"npc/shanzheng" : 1,
        ]));
 
	setup();
}
