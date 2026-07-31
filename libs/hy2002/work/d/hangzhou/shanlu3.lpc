// shanlu3.c
// Date: Nov.1997 by Venus
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "山路");
        set("long", @LONG
小溪横过山路，跨溪有一座小石桥。溪边农家小孩在嬉戏玩乐。                    
南上便到了上天竺。北下就是中天竺。
LONG);
        set("exits", ([
            "southup"   : __DIR__"faxisi",
            "northdown" : __DIR__"fajinsi",
        ]));
        set("objects", ([
            __DIR__"npc/boy" : 3,
"quest/skills2/wunon/non/nontian" : 2,
        ]));
        set("outdoors", "hangzhou");
//        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
