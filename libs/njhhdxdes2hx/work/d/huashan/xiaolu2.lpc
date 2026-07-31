// Room: /d/shaolin/jlyuan.c
// Date: YZC 96/01/19


#include <ansi.h>
#include <login.h>

inherit ROOM;

void create()
{
        set("short", "小路");
        set("long", @LONG
你走在一条小路上，小路一侧是悬崖，另一侧则是峭壁。路上若有两人相对而行，
必须侧身才能通过。路上寸草未生，你向上一看，有一些小松从峭壁中伸出。
LONG
        );
        
        set("exits", ([
                "east" : __DIR__"xiaolu1",
                "westup" : __DIR__"xiaolu3",
        ]));

        setup();
        set("no_clean_up", 0);
        setup();


}
