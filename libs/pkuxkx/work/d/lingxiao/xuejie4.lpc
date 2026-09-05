// File         : xuejie4.c
// Created By   : iszt@pkuxkx, 2006-08-15

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", WHT"雪街"NOR);
        set("long", @LONG
也许是因为雪街是凌霄城「城」之所在，街上的气氛比之冰街要轻松很多。
几名弟子在来回闲逛，偶尔也相互交手，切磋技艺。巡逻的弟子也少了些。北边
搭起一个戏台，里边好不热闹；南边是一家鞋店，门口一副对联道是：「步月凌
云去，登堂入室来。」
LONG);
        set("outdoors", "凌霄城");
        set("exits", ([
                "west" : __DIR__"bingjie3",
                "east" : __DIR__"xuejie5",
                "north" : __DIR__"xuenorth4",
                "south" : __DIR__"xuesouth4",
        ]));
        set("objects", ([
                __DIR__"npc/dizi_free" : 2,
        ]));

        setup();
        replace_program(ROOM);
}
