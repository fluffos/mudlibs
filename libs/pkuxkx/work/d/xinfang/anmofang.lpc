// 按摩房	按摩房
// By bing

#include <ansi.h>
inherit ROOM;

void init();

void create()
{
        set("short", HIY"按摩房"NOR);
        set("long", @LONG
这里是宾馆新开张的按摩房。请来的都是一流的按摩师，据说
是来自遥远的岛国——东瀛。屋角燃着一炉檀香，一位身穿和
服的女子正跪坐在房内轻弹古筝。几个按摩师正在给客人按摩。
LONG
        );

        set("exits", ([
                  "north" : __DIR__"bathroad",
        ]));

        set("objects",([
                __DIR__"npc/anmogirl" : 1,
        ]));

        set("no_fight", 1);

        setup();
}

