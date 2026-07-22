#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "试剑石");
        set("long", @LONG
这里是雁荡后山的试剑石，传说中八仙之一的吕洞宾曾在这里磨剑
试剑，之间山腰的空地上到处都是方方正正的大石头，都如刀削般
整齐，鬼斧神工似的棱角分明，
LONG );
        set("outdoors", "yandang");
        set("exits", ([ /* sizeof() == 2 */
            "northup" : __DIR__"laoniubei",
            "southdown":__DIR__"xianrensong" ,
        ]));
        set("no_clean_up", 0);
        setup();
}


