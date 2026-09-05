#include <ansi.h>
#include <room.h>
inherit ROOM; 

void create()
{     set("short", HIW "鹰王宫" NOR);
        set("long", @LONG
     这里就是鹰王宫的大厅。正前方挂着一幅巨画，一只苍鹰正
 探出利爪扑击野兔，画中苍鹰神威凛然，体形健硕。画的上方挂
 有一面横匾,上书"鹰爪王"三个大字。原来教主阳顶天念在殷天正
 为明教立下了赫赫功勋，年事将高，于是造了这座鹰王宫给其颐
 养天年。
LONG
        );
        set("exits", ([
                "south" : __DIR__"wuchang",
                "west" : __DIR__"tianweitang",
                "north" : __DIR__"ziweitang",
                "east" : __DIR__"tianshitang",
        ]));
        set("objects", ([
                CLASS_D("mingjiao") + "/yintianzheng" : 1 ]));
        create_door("south", "宫门", "north", DOOR_CLOSED);
      set("outdoors", "mingjiao");
        setup();
}
