//pkroom1.c by becool, 2008-11-21
#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIR"单挑室"NOR );
        set("long", @LONG
这是一间阴森森的大屋子，昏暗的灯光被墙上的排气扇吹得摇曳不定。
角落里有两个侏儒模样的小人跪在地上慢腾腾的擦着什么，阵阵的血腥味
让你直想吐。
LONG);
        set("objects", ([
        "/d/pvp/npc/chonger2p": 1,
        ]));
        set("exits", ([
                "out" : "/d/pvp/entrance",
        ]));
        set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        set("max_user", 2);
        setup();
}
int valid_leave(object me, string dir)
{
        if ( dir =="out" && me->is_fighting())
                {
                message_vision(HIW"$N想逃跑，却被"HIR"虫二"HIW"一把拽了回来。\n"NOR,this_player());
                return notify_fail(HIW"想逃？恐怕晚喽！\n"NOR);
                }
        return :: valid_leave(me, dir);
}
