#include <ansi.h>;
inherit ROOM;
void create()
{
        set("short", HIW"虫二"HIR"工作室"NOR);
        set("long", "这是间大屋子，里面挤满了美女，根本没地方摆家具。\n");
        set("objects", ([
        "/kungfu/class/gumu/longer": 1,
        "/kungfu/class/murong/azhu": 1,
        "/d/city/obj/furnace": 1,
        ]));
        set("exits", ([
        "south" : "/u/becool/guestroom",
        "west" : __DIR__"dream_room" ,
        "north" : "/d/wizard/wizard_room_whuan",
        "east" : "/u/becool/biwuchang",
        "southeast" : "/u/becool/trashroom",
        ]));
        set("valid_startroom", 1);
        set("outdoors", "city");
        setup();
        call_other("/clone/board/wiz_b", "???");
}
