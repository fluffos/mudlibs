// /area/jiangbei/wudang/yuanhe.c 元和观
// By River@SJ

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", HIW"元和观"NOR);
        set("long", @LONG
元和观是武当山进玄岳门古神道上的第一座道观。据道藏记载，玄天上帝
修练得道后，曾掌管“元和迁校府”，故这座道观取名“元和观”。这里，迁，
是放逐的意思；校，是指枷锁等刑具。事实上，元和观是武当派处罚违犯清规
戒律的武当弟子的机构。
LONG
        );

        set("exits", ([
                "southup" : __DIR__"gsdao2",
                "northdown" : __DIR__"gsdao1",
                "east" : __DIR__"yuanhe1",
        ]));

        set("objects",([
                __DIR__"npc/daotong" : 1,
        ]));

        set("no_clean_up", 0);
        set("outdoors", "武当");

        setup();
}
