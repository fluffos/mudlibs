#include <ansi.h>
inherit ROOM;
int do_none();
void create()
{
        set("short", HIR"比武场"NOR );
        set("long", HIY@LONG
一坨莲花的私人比武场，武器、活靶子，应有尽有。
LONG NOR);
        set("exits", ([
                "west" : "/d/wizard/wizard_room_becool",
                "east" : "/d/pvp/entrance",
        ]));
        set("objects",([
                "/d/yuewangmu/obj/dpqiang" : 2,
                "/u/becool/npc/peilian" : 1,
        ]));
        set("no_die", 1);
        set("no_clean_up", 0);
        set("outdoors", "xx" );
        setup();
}
