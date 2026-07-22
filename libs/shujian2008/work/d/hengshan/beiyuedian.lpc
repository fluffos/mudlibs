// Room: /d/hengshan/beiyuedian.c
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "北岳殿");
        set("long", @LONG
北岳殿上负绝壁，下临宫廨，下云级插天，庑门上下，穹碑森立。殿正中
悬风字形匾，上书“贞元之殿”，殿内北岳恒山之神全身塑像，高可丈余。
LONG);
        set("exits", ([ /* sizeof() == 4 */
           "westup"    : __DIR__"huixiantai",
           "eastup"    : __DIR__"yuyang",
           "northup"   : __DIR__"shandao1",
           "southdown" : __DIR__"beiyuemiao",
        ]));
        set("outdoors", "恒山");
        set("no_clean_up", 0);
        setup();
}
