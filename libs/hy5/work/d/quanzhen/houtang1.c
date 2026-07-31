// houtang1.c 后堂一进
// By Lgg,1998.10

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "后堂一进");
        set("long", @LONG
这里是后堂的一进，是平常全真教弟子休息的地方。由于全真教
现在广收弟子，堂中摆放的桌椅也不断增加，显得这个堂已经很拥挤
了。
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([
                "east" : __DIR__"houtang2",
                "west" : __DIR__"laojundian",
        ]));

        setup();
        replace_program(ROOM);
}
