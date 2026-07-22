//Edit By Subzero
#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{

        set("short", "休息室" );
        set("long", @LONG
这里就是供弟子临时休息的地方，床上摆放着整齐的被褥，看上去
就让人感到很想睡觉。
LONG);

        set("sleep_room", 1);
        set("no_fight", 1);
        set("valid_startroom", 1);
        set("no_get", 1);
        set("exits", ([
        "east" : __DIR__"ygrestroom1",
        ]));

        setup();
}
