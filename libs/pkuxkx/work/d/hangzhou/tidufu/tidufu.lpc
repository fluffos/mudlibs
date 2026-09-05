// Room: /hangzhou/tidufu.c
// hubo 2008/4/19
 
#include <ansi.h>

inherit "/d/hangzhou/song_room";
#include <ansi.h>

void create()
{
        set("short", HIR"提督府正门"NOR);
        set("long", @LONG
这是杭州城的政治军事中心：提督府。两扇红漆大门庄严肃穆，无人敢
在此逗留太久，大门两侧，各有一大石狮子。府门前有几个卫兵站岗放哨，
盯着过往的每一个人。
LONG
        );
        set("outdoors", "hangzhou");

        set("exits", ([
                "east" : "/d/hangzhou/nanmen",
                "west" : __DIR__"td_dadao1",
        ]));
        
        set("objects", ([
                "/d/hangzhou/npc/qingbing" : 4,
        ]));     

        setup();
}

int valid_leave(object me, string dir)
{
                
    if (me->query("special_skill/sociability"))
        return ::valid_leave(me, dir);
    if (dir == "west"
    && objectp(present("qing bing", environment(me)))
    && living(present("qing bing", environment(me))))
        return notify_fail("清兵说道：赶快滚开，这是你停留的地方吗？”\n");
    return ::valid_leave(me, dir);
}
