// biwuchang.c - 比武场
// 编程：中山大学  张三丰（Micro）----Micro_Liang@Hotmail.Com           1997.7

#include <room.h>

inherit ROOM;

string look_sign();

void create()
{
        set("short", "比武场");
        set("long", @LONG

    这里是侠客城的比武场。你可以看到正前方就是比武场的大门（door）。
LONG
        );

        set("outdoors", "center");
        set("only_wiz_open", 1);
        set("only_wiz_close", 1);

        set("item_desc", ([
                "door": @TEXT
你可以通过大门进入（enter）比武场所内。
TEXT
        ]) );

        set("exits", ([
                "east"  : __DIR__"wuguan",
                "south" : __DIR__"gongyuan",
                "north" : __DIR__"taolunshi",
                "enter" : __DIR__"biwuchang_watch_room",
        ]) );                   

        setup();

        create_door("enter", "镶着铜钉的大门", "out", DOOR_CLOSED);
}

