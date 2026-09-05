// houshanxiaolu2.c
// by airy
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "碎石路");
        set("long", @LONG
   你走在一条碎石路上。两旁是一片稻田，几个农夫在田间劳作，
往北走就快到鹰王宫了。往南走是到光明顶
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"suishilu3",
                "southup" : __DIR__"suishilu1",
        ]));
 set("outdoors", "mingjiao");
        setup();
      replace_program(ROOM);
}
