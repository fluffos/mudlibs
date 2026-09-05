//mshishi.c
//by hehe
//2003.3.5

#include <room.h>
inherit ROOM;

void create()
{
    set("short", "石室");
    set("long", @LONG
这里是曼陀山庄的花肥房，是曼陀山庄存放花肥的地方，
也是曼陀山庄关押犯人的地方，平时有什么被王夫人抓
回来就关在这里，房里放满了刑具。
LONG
    );

    set("exits", ([
		"east" : __DIR__"mroad8",
    ]));
    set("objects", ([
		"/d/murong/npc/yan" : 1,
	]));
    set("outdoors", "murong");
    setup();

}
