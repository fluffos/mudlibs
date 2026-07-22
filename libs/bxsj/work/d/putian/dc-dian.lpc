// Room: /d/putian/dc-dian.c 大乘殿
// lklv 2001.9.12

#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "大乘殿");
        set("long", @LONG
这里是大乘殿，殿中香火很多，门口有一个镂刻得十分精美的大香炉，香
炉前面是一张深色的供桌，桌后面立着一个很大的屏风。屏风后面靠墙壁高高
的摆放着几尊佛像。大殿南面也有一个门。
LONG
        );

        set("exits", ([
                "north" : __DIR__"xj4",
                "southup" : __DIR__"wgg",
                "west" : __DIR__"lhtang",
        ]));

        set("objects",([
                __DIR__"npc/shami" : 2,
                __DIR__"npc/wuseng" : 2,
        ]));

        setup();
}
