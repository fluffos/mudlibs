// Room: /d/beijing/ludinggong.c
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIC"鹿鼎公府大院"NOR);
        set("long",
CYN"眼前大门洞开着，连个看守的人都没有，隔着院墙听见府里传出一
阵吹吹打打的声音，听来是在演戏，还夹杂着一阵阵吆喝声、惊叹欢呼
声、咒骂声、哄笑声和噼哩啪啦的声响，汇成一片，搅在一起，应该是
一帮人在赌得正高兴发出的，听闻这鹿鼎公十分好赌，看来是错不了。\n"NOR
        );

        set("exits", ([
                "south" : __DIR__"guloudajie_w2",
                 "west" : __DIR__"tingyuan",

        ]));
 	set("outdoors", "beijing");
        setup();
        replace_program(ROOM);
}


