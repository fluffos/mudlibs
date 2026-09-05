#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", HIW"虫二"HIR"会客室"NOR);
        set("long", "这是虫子的会客室，装修简约舒适，墙上贴满了美女图片。\n");
        set("exits", ([
        "south" : "/d/city/guangchang",
        "north" : "/d/wizard/wizard_room_becool",
        ]));
        set("outdoors", "city");
        setup();
}

int valid_leave(object me, string dir)
{
        if ( dir =="north" && !wizardp(me))
                return notify_fail("你想去虫二的工作室瞧瞧，但是门口挤满了美女，死活钻不进去。\n");
        return ::valid_leave(me, dir);
}
