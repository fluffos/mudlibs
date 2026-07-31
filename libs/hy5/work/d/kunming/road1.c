// /d/kunming/road1
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "乱石滩" NOR);
        set("long", @LONG
这里怪石林立，路极不好走，不小心就要摔个跟斗，过了这片石滩，就
是长江岸边。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "south" : __DIR__"road3", 
                "southwest" : __DIR__"road2",
                "northdown" : "/d/jingzhou/nanshilu1",
        ]));

        setup();
        replace_program(ROOM);
}
