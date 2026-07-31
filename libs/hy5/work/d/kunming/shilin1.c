// /d/kunming/shilin1
// netkill /98/8/14/

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY "阿诗玛" NOR);
        set("long", @LONG
这里是石林著名的阿诗玛峰，相传很就以前，美丽的哈尼族姑娘
阿诗玛在此等侯他的阿黑哥，然而阿黑却被地主老财杀害了，阿诗玛
等啊等，始终没有等来心爱的情郎，终究化作了一座石峰，永远的守
侯下去。
LONG
        );
        set("outdoors", "kunming");

        set("exits", ([
                "northeast" : __DIR__"shilin", 
                "west"  :__DIR__"shilin2",
                
                
        ]));

             
        setup();
        replace_program(ROOM);
}
