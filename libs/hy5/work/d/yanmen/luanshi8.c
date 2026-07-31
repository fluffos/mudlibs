// Create by lonely@NT
inherit ROOM;
#include <ansi.h>;
void create()
{
        set("short", HIW"乱石路"NOR);
        set("long",
"这里是雁门关的乱石路,是扼守南北的交通必经之路，历来为兵家必\n"
"争之地，由山顶币制而下，只有一条狭窄的羊肠小道，两面则是堆满乱石，\n"
"好象暗浮杀机。\n"
);
        set("outdoors", "yanmen");
        set("exits", ([
                "north" :  __DIR__"luanshi7",
                "south" :  __DIR__"shibi",
        ]));
        set("no_fly",1);
        setup();
        replace_program(ROOM);
}
