// donglang1.c 东厢走廊
// by Xiang
// Modified by Marz 03/27/96
#include <room.h>
inherit ROOM;
void create()
{
    set("short", "朝天宫");
    set("long", @LONG
这里是一座金碧辉煌的大殿，匾上书朝天宫三个金字。南边是虎
头岩，北边是三天门，人来人往很热闹。
LONG
    );
    set("exits", ([
        "south" : __DIR__"hutou",
        "north" : __DIR__"santian",
    ]));
    
    set("objects", ([
        CLASS_D("wudang") + "/xi" : 1]));
        
    setup();
}
int valid_leave(object me, string dir)
{
    mapping myfam;
    object ob;
    myfam = (mapping)me->query("family");
    ob=present("zhang songxi", environment(me));
    if (objectp(ob) && living(ob))
    if ( wizardp(ob))
    if ((!myfam || myfam["family_name"] != "武当派") && dir == "north" )
       return notify_fail("张松溪喝道：你不是武当弟子，不得入内。\n");
        
        return ::valid_leave(me, dir);
}
