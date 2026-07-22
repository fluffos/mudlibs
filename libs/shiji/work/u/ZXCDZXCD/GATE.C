#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "皇宫大门");
        set("long", @LONG
脚下是一片很大的广场,这里是兽族最大议会场所.屹立在你的
是一道用大红檀木精心雕刻的大门,气势恢弘.门外还守卫着两排
兽族勇士,看起来誓死保卫皇宫的样子.如果你想硬闯的话,一定
还会惊动不少兽族高手.
LONG);
    set("exits", (
     "north" : __DIR__"shibanlu",
     "enter" : __DIR__"huatan",
    ]));
 set("objects", ([   "/kungfu/class/shouzu/yongshi": 4        ]));
    setup();
    replace_program(ROOM); 
}
