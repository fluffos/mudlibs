// /d/city/beidajie2.c

#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "北大街");
	set("long", @LONG
你走在一条繁忙的街道上，看着操着南腔北调的人们行色匆匆，许多人都
往南边走去，那里通向一个热闹的广场。东边是一家生意兴隆的宝昌客栈，来
自各地的人们进进出出。西边是扬州一家老字号的钱庄，名为天阁斋。可以听
到叮叮当当的金银声音。
LONG
        );
	set("outdoors", "扬州");

	set("exits", ([
                "east" : __DIR__"kedian",
                "south" : __DIR__"beidajie3",
                "west" : __DIR__"qianzhuang",
                "north" : __DIR__"beidajie1",
        ]));

        set("objects", ([
                CLASS_D("gaibang/qigai") : 1,
        ]));
	set("incity",1);
	setup();
}

void init()
{
        object me = this_player();

	if (userp(me) && me->query("combat_exp") >1000000 && (int)me->query("jingli") < 500) {
                message_vision(HIY"只见$N脚下一滑，仰面摔了个大马趴，原来$N踩了个西瓜皮。\n"NOR,me);
                me->start_busy(2);
        }
        return;
}