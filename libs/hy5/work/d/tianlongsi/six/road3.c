#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"白石路"NOR);
        set("long", @LONG
这里又是一段白石路，石面平滑，打扫得干干净净。路旁种有各式花
草，两株参天大树分立左右两边。
LONG);
        set("outdoors", "天龙寺");
        set("exits", ([             
               "west" : __DIR__"wwj",
        ]));

        setup();
        replace_program(ROOM);
}